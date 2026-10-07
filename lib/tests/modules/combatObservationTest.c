//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Actor;
object Target;
object Room;
object Kata;
object Prerequisite;
object Weapon;
object Mastery;

void Setup()
{
    Actor = clone_object(
        "/lib/tests/support/services/observationCombatActor.c");
    Actor.Name("Kata practitioner");
    Actor.ToggleMockResearch();
    Actor.toggleKillList();
    Actor.Str(20);
    Actor.Int(20);
    Actor.Dex(20);
    Actor.Con(20);
    Actor.Wis(20);
    Actor.Chr(20);
    Target = clone_object("/lib/realizations/monster.c");
    Target.Name("Bob");
    Target.addAlias("bob");
    Target.Race("orc");
    Target.staminaPoints(1000);
    Room = clone_object("/lib/environment/environment.c");
    move_object(Actor, Room);
    move_object(Target, Room);
    Weapon = clone_object("/lib/items/weapon.c");
    Weapon.set("blueprint", "katana");
    move_object(Weapon, Actor);
    ExpectTrue(Actor.equip(Weapon), "equipped katana");
    Kata = clone_object("/lib/tests/support/research/falling-leaf.c");
    Mastery = clone_object(
        "/lib/tests/support/research/falling-leaf-mastery.c");
    Prerequisite = clone_object(
        "/lib/tests/support/research/prerequisiteItem.c");
}

void CleanUp()
{
    destruct(Mastery);
    destruct(Weapon);
    destruct(Prerequisite);
    destruct(Kata);
    destruct(Target);
    destruct(Actor);
    destruct(Room);
}

void HundredSuccessfulKatasUnlockObservationRules()
{
    mapping criteria = ([
        "type": "combat.kata",
        "target race": "orc",
        "target name": "Bob",
        "weapon": "katana",
        "season": getService("environment")->season(),
        "moon phase": getService("environment")->moonPhase(),
        "time of day": getService("environment")->timeOfDay(),
        "kata": "falling-leaf",
        "research": program_name(Kata)
    ]);
    ExpectTrue(Prerequisite.AddTestPrerequisite("kata mastery", ([
        "type": "observation",
        "criteria": criteria,
        "value": 100
    ])));
    for (int iteration = 0; iteration < 99; iteration++)
    {
        Actor.unregisterAttacker(Target);
        Target.unregisterAttacker(Actor);
        Actor.heart_beat();
        ExpectTrue(Kata.execute("falling leaf at bob", Actor));
    }
    ExpectEq(99, Actor.countObservations(criteria));
    ExpectFalse(Prerequisite.checkPrerequisites(Actor));
    ExpectFalse(Mastery.checkPrerequisites(Actor), "mastery blocked at 99");
    Actor.unregisterAttacker(Target);
    Target.unregisterAttacker(Actor);
    Actor.heart_beat();
    ExpectTrue(Kata.execute("falling leaf at bob", Actor));
    ExpectEq(100, Actor.countObservations(criteria));
    ExpectTrue(Prerequisite.checkPrerequisites(Actor), "prerequisite at 100");
    ExpectTrue(Mastery.checkPrerequisites(Actor), "mastery available at 100");
    mapping rule = criteria + ([ "minimum": 100 ]);
    ExpectTrue(getService("limitor")->userFactorsMet(([
        "limited by": ([ "observation": rule ])
    ]), Actor), "limitor at 100");
    rule["minimum"] = 101;
    ExpectFalse(getService("limitor")->userFactorsMet(([
        "limited by": ([ "observation": rule ])
    ]), Actor));
    ExpectEq(0, Actor.countObservations(([ "type": "combat.hit" ])));
}

void FailedKataDoesNotRecordObservation()
{
    ExpectFalse(Kata.execute("falling leaf at nobody", Actor));
    ExpectEq(0, Actor.countObservations(([ "type": "combat.kata" ])));
}

/////////////////////////////////////////////////////////////////////////////
void CombatTransitionsRecordOnlyChangedHostility()
{
    ExpectTrue(Actor.registerAttacker(Target));
    ExpectTrue(Actor.registerAttacker(Target));
    ExpectTrue(Actor.supercedeAttackers(Target));
    ExpectEq(1, Actor.countObservations(([ "type":"combat.started" ])));
    ExpectTrue(Target.registerAttacker(Actor));
    Actor.stopFight(Target);
    Actor.stopFight(Target);
    ExpectEq(1, Actor.countObservations(([ "type":"combat.ended" ])));
    ExpectEq(1, Target.countObservations(([ "type":"combat.ended" ])));
    ExpectFalse(Actor.isInCombatWith(Target));
    ExpectFalse(Target.isInCombatWith(Actor));
}

/////////////////////////////////////////////////////////////////////////////
void DeathRecordsVictimAndKillerWithoutDuplicates()
{
    ExpectTrue(Actor.registerAttacker(Target));
    ExpectTrue(Target.registerAttacker(Actor));
    Actor.hit(100000, "fire", Target);
    ExpectTrue(Actor.isDead());
    ExpectEq(1, Actor.countObservations(([ "type":"combat.death" ])));
    ExpectEq(1, Target.countObservations(([ "type":"combat.kill" ])));
    ExpectEq(1, Actor.countObservations(([ "type":"combat.ended" ])));
    Actor.hit(100000, "fire", Target);
    ExpectEq(1, Actor.countObservations(([ "type":"combat.death" ])));
    ExpectEq(1, Target.countObservations(([ "type":"combat.kill" ])));
}