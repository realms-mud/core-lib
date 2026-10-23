//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Teacher;
object Target;
object Room;
object Weapon;
string Palm = "/guilds/monk/unarmed/measured-palm.c";
string Recovery = "/guilds/monk/unarmed/balanced-recovery.c";
string KataCommand = "kata measured palm at opponent";

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/guilds/monk/monk.c");
    ignoreList += ({ "PrepareStudent", "ReadyKata" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Room = clone_object("/lib/environment/environment.c");
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("student");
    User.Str(20);
    User.Int(20);
    User.Dex(20);
    User.Con(20);
    User.Wis(20);
    User.Chr(20);
    User.Race("human");
    User.colorConfiguration("none");
    Teacher = clone_object("/guilds/monk/teachers/lian.c");
    Target = clone_object("/lib/realizations/npc.c");
    Target.Name("opponent");
    Target.Race("human");
    Target.effectiveLevel(3);
    Target.setMaxHitPoints(10000);
    Weapon = clone_object("/lib/items/weapon.c");
    Weapon.set("blueprint", "long sword");
    Weapon.set("name", "sword");
    move_object(User, Room);
    move_object(Teacher, Room);
    move_object(Target, Room);
    move_object(Weapon, User);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Weapon);
    if (Target)
    {
        destruct(Target);
    }
    destruct(Teacher);
    destruct(User);
    destruct(Room);
}

/////////////////////////////////////////////////////////////////////////////
void PrepareStudent()
{
    ExpectTrue(User.joinGuild("monk"));
    ExpectFalse(member(User.availableResearchTrees(),
        "/guilds/monk/unarmed.c") >= 0);
    ExpectTrue(User.learnResearchFrom(Teacher,
        "/guilds/monk/discipline/initiates-discipline.c"));
    int advancing = 1;
    while (advancing && User.guildLevel("monk") < 5)
    {
        User.addExperience(User.experienceToNextLevel("monk"), "monk");
        advancing = User.advanceLevel("monk");
    }
    ExpectEq(5, User.guildLevel("monk"));
    ExpectTrue(member(User.availableResearchTrees(),
        "/guilds/monk/unarmed.c") >= 0);
    ExpectTrue(User.isResearched("/guilds/monk/unarmed/root.c"));
    ExpectTrue(User.initiateResearch(
        "/guilds/monk/discipline/disciplined-breath.c"));
    ExpectTrue(User.advanceRank("monk"));
    ExpectFalse(User.initiateResearch(Palm));
    ExpectTrue(User.learnResearchFrom(Teacher, Palm));
}

/////////////////////////////////////////////////////////////////////////////
void ReadyKata()
{
    User.stopFight(Target);
    Target.stopFight(User);
    for (int tick = 0; tick < 4; tick++)
    {
        User.heart_beat();
    }
    User.hitPoints(10000);
    User.staminaPoints(10000);
    ExpectTrue(Target.registerAttacker(User));
    ExpectTrue(User.registerAttacker(Target));
}

/////////////////////////////////////////////////////////////////////////////
void KataUsesNormalDamageCostsCooldownAndOneObservation()
{
    PrepareStudent();
    ReadyKata();
    int health = Target.hitPoints();
    int stamina = User.staminaPoints();
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectTrue(Target.hitPoints() < health);
    ExpectTrue(health - Target.hitPoints() <= 30);
    ExpectEq(stamina - 6, User.staminaPoints());
    ExpectTrue(User.blockedByCooldown(Palm));
    ExpectTrue(User.spellAction() > 0);
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata",
        "research":Palm,
        "qualifying opponent":1
    ])));
    stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(stamina, User.staminaPoints());
    ReadyKata();
    ExpectEq(1, User.countObservations(([ "type":"combat.kata" ])));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(2, User.countObservations(([ "type":"combat.kata" ])));
}

/////////////////////////////////////////////////////////////////////////////
void BothHandsMustBeEmptyAndEquipmentChangesTakeEffectImmediately()
{
    PrepareStudent();
    ReadyKata();
    int stamina = User.staminaPoints();
    ExpectTrue(Weapon.equip("sword"));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectFalse(load_object(Palm).execute(KataCommand, User));
    ExpectEq(stamina, User.staminaPoints());
    ExpectEq(0, User.countObservations(([ "type":"combat.kata" ])));
    ExpectTrue(Weapon.unequip("sword"));
    ExpectTrue(Weapon.equip("sword offhand"));
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectTrue(Weapon.unequip("sword"));
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(stamina - 6, User.staminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void TenQualifyingExecutionsUnlockInstructionWithoutAnotherCounter()
{
    PrepareStudent();
    for (int index = 0; index < 10; index++)
    {
        ReadyKata();
        ExpectFalse(User.canResearch(Recovery));
        ExpectFalse(User.learnResearchFrom(Teacher, Recovery));
        ExpectTrue(User.executeCommand(KataCommand));
        ExpectEq(index + 1, User.countObservations(([
            "type":"combat.kata",
            "research":Palm,
            "qualifying opponent":1
        ])));
    }
    ExpectTrue(User.canResearch(Recovery));
    ExpectFalse(User.initiateResearch(Recovery));
    int points = User.researchPoints();
    ExpectTrue(User.learnResearchFrom(Teacher, Recovery));
    ExpectEq(points - 2, User.researchPoints());
    ExpectEq(1, User.researchBonusTo("dodge"));
    ReadyKata();
    ExpectTrue(Weapon.equip("sword"));
    ExpectEq(0, User.researchBonusTo("dodge"));
    ExpectTrue(Weapon.unequip("sword"));
    ExpectEq(1, User.researchBonusTo("dodge"));
    ExpectFalse(User.learnResearchFrom(Teacher, Recovery));
    ExpectEq(points - 2, User.researchPoints());
}

/////////////////////////////////////////////////////////////////////////////
void OpeningStrikesAndTrivialOpponentsDoNotQualifyAsPractice()
{
    PrepareStudent();
    ReadyKata();
    Target.stopFight(User);
    User.stopFight(Target);
    ExpectTrue(User.executeCommand(KataCommand));
    mapping first = User.queryObservations(([ "type":"combat.kata" ]))[0];
    ExpectEq(0, first["context"]["qualifying opponent"]);
    ExpectEq(0, first["context"]["opponent engaged"]);
    Target.effectiveLevel(2);
    ReadyKata();
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(0, User.countObservations(([
        "type":"combat.kata", "qualifying opponent":1
    ])));
    Target.effectiveLevel(3);
    ReadyKata();
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectEq(1, User.countObservations(([
        "type":"combat.kata", "qualifying opponent":1
    ])));
}

/////////////////////////////////////////////////////////////////////////////
void AlliedNpcIsExcludedEvenWhenItIsRegisteredAsHostile()
{
    PrepareStudent();
    ReadyKata();
    Target.setLeader(User, 1);
    mapping context = getService("experiences")->buildObservationContext(
        User, ([ "type":"combat.kata", "subject":Target ]));
    ExpectEq(1, context["opponent allied"]);
    ExpectEq(1, context["opponent engaged"]);
    ExpectEq(0, context["qualifying opponent"]);
}

/////////////////////////////////////////////////////////////////////////////
void InvalidTargetsAndInsufficientResourcesDoNotProducePractice()
{
    PrepareStudent();
    ReadyKata();
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand("kata measured palm at missing"));
    ExpectEq(stamina, User.staminaPoints());
    User.staminaPoints(-10000);
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(0, User.countObservations(([ "type":"combat.kata" ])));
}

/////////////////////////////////////////////////////////////////////////////
void KillingBlowRetainsPreEffectPracticeFacts()
{
    PrepareStudent();
    ReadyKata();
    Target.setMaxHitPoints(1);
    ExpectEq(1, Target.hitPoints());
    ExpectTrue(User.executeCommand(KataCommand));
    ExpectTrue(!Target || Target.isDead());
    mapping observation = User.queryObservations(([
        "type":"combat.kata", "research":Palm
    ]))[0];
    ExpectEq(1, observation["context"]["target alive"]);
    ExpectEq(1, observation["context"]["qualifying opponent"]);
}

/////////////////////////////////////////////////////////////////////////////
void DeadOrRemoteOpponentsDoNotQualifyEvenWithHostilityRegistered()
{
    PrepareStudent();
    ReadyKata();
    Target.Ghost(1);
    ExpectTrue(Target.isDead());
    mapping context = getService("experiences")->buildObservationContext(
        User, ([ "type":"combat.kata", "subject":Target ]));
    ExpectEq(1, context["opponent engaged"]);
    ExpectEq(0, context["target alive"]);
    ExpectEq(0, context["qualifying opponent"]);
    Target.Ghost(1);
    move_object(Target, this_object());
    context = getService("experiences")->buildObservationContext(
        User, ([ "type":"combat.kata", "subject":Target ]));
    ExpectEq(0, context["qualifying opponent"]);
    int stamina = User.staminaPoints();
    ExpectFalse(User.executeCommand(KataCommand));
    ExpectEq(stamina, User.staminaPoints());
    ExpectEq(0, User.countObservations(([ "type":"combat.kata" ])));
}
