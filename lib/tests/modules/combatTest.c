
//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Attacker;
object Target;
object Room;

/////////////////////////////////////////////////////////////////////////////
varargs void SetUpAttacker(int useRealThing)
{
    Attacker = useRealThing ? clone_object("/lib/realizations/player.c") :
        clone_object("/lib/tests/support/services/combatWithMockServices");

    Attacker.Name("Bob");
    Attacker.Str(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Int(20);
    Attacker.Wis(20);
}

/////////////////////////////////////////////////////////////////////////////
void SetUpTarget()
{
    Target = clone_object("/lib/tests/support/services/testMonster.c");
    Target.Name("Nukulevee");
    Target.Race("undead horse");
    Target.effectiveLevel(20);
    Target.Str(20);
    Target.Dex(20);
    Target.Con(20);
    Target.Int(20);
    Target.Wis(20);
}

/////////////////////////////////////////////////////////////////////////////
object CreateWeapon(string name)
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", name);
    weapon.set("defense class", 2);
    weapon.set("weapon class", 10);
    weapon.set("bonus hit points", 2);
    weapon.set("material", "galvorn");
    weapon.set("weapon type", "long sword");
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attacker);

    return weapon;
}

/////////////////////////////////////////////////////////////////////////////
object CreateShield(string name)
{
    object shield = clone_object("/lib/items/weapon");
    shield.set("name", name);
    shield.set("defense class", 1);
    shield.set("bonus constitution", 3);
    shield.set("material", "steel");
    shield.set("craftsmanship", 20);
    shield.set("equipment locations", Shield);
    shield.set("weapon type", "shield");
    move_object(shield, Attacker);

    return shield;
}

/////////////////////////////////////////////////////////////////////////////
object CreateArmor(string name)
{
    object armor = clone_object("/lib/items/armor");
    armor.set("name", name);
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Attacker);

    return armor;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpAttacker", "SetUpTarget", "CreateWeapon", "CreateArmor",
        "CreateShield" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    SetUpAttacker();
    SetUpTarget();
    Room = clone_object("/lib/tests/support/environment/fakeCombatRoom");
    move_object(Attacker, Room);
    move_object(Target, Room);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Room);
    destruct(Target);
    destruct(Attacker);
}

/////////////////////////////////////////////////////////////////////////////
void AddAttackDoesNotAddInvalidAttacks()
{
    // With no attacks set, one unarmed attack is created
    ExpectEq(1, sizeof(Attacker.getAttacks()), "1 attack is in the list");
    ExpectFalse(Attacker.addAttack("blah", 10, 10), "blah attack is not added");
    ExpectEq(1, sizeof(Attacker.getAttacks()), "1 attack is in the list");
    ExpectEq("unarmed", Attacker.getAttacks()[0]["attack type"], "unarmed attack exists");
}

/////////////////////////////////////////////////////////////////////////////
void AddAttackAddsValidAttacks()
{
    ExpectTrue(Attacker.addAttack("claw", 10, 10), "claw attack added");
    ExpectEq(1, sizeof(Attacker.getAttacks()), "1 attack is in the list");
    ExpectEq("claw", Attacker.getAttacks()[0]["attack type"], "claw attack was added");
}

/////////////////////////////////////////////////////////////////////////////
void AddAttackAddsMultipleAttacks()
{
    // With no attacks set, one unarmed attack is created
    ExpectTrue(Attacker.addAttack("claw", 10, 10), "claw attack added");
    ExpectTrue(Attacker.addAttack("horn", 10, 10), "horn attack added");
    ExpectTrue(Attacker.addAttack("teeth", 10, 10), "teeth attack added");
    ExpectTrue(Attacker.addAttack("fire", 10, 10), "fire attack added");
    ExpectTrue(Attacker.addAttack("cold", 10, 10), "cold attack added");
    ExpectFalse(Attacker.addAttack("fake", 10, 10), "fake attack added");
    ExpectEq(5, sizeof(Attacker.getAttacks()), "5 attacks were added");
}

/////////////////////////////////////////////////////////////////////////////
void ClearAttacksClearsAllAttacks()
{
    ExpectTrue(Attacker.addAttack("claw", 10, 10), "claw attack added");
    ExpectTrue(Attacker.addAttack("horn", 10, 10), "horn attack added");
    ExpectEq(2, sizeof(Attacker.getAttacks()), "1 attack is in the list");
    ExpectEq("claw", Attacker.getAttacks()[0]["attack type"], "claw attack was added");
    Attacker.clearAttacks();
    ExpectEq(1, sizeof(Attacker.getAttacks()), "only 1 attack in the list");
    ExpectEq("unarmed", Attacker.getAttacks()[0]["attack type"], "unarmed attack in list");
}

/////////////////////////////////////////////////////////////////////////////
void GetAttacksReturnsWeaponAttack()
{
    object weapon = CreateWeapon("blah");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    ExpectEq(1, sizeof(Attacker.getAttacks()), "1 attack returned");
    ExpectEq("wielded primary", Attacker.getAttacks()[0]["attack type"], "weapon attack in list");
}

/////////////////////////////////////////////////////////////////////////////
void GetAttacksDoesNotReturnWieldedNonAttackShields()
{
    object weapon = CreateWeapon("blah");
    object shield = CreateShield("shield");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(shield.equip("shield offhand"), "shield equip called");

    ExpectEq(1, sizeof(Attacker.getAttacks()), "1 attack returned");
    ExpectEq("wielded primary", Attacker.getAttacks()[0]["attack type"], "weapon attack in list");
}

/////////////////////////////////////////////////////////////////////////////
void GetAttacksReturnsWieldedShieldsWithAttacks()
{
    object weapon = CreateWeapon("blah");
    object shield = CreateShield("shield");
    shield.set("weapon class", 1);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(shield.equip("shield offhand"), "shield equip called");

    ExpectEq(2, sizeof(Attacker.getAttacks()), "2 attack returned");
    ExpectEq("wielded primary", Attacker.getAttacks()[0]["attack type"], "weapon attack in list");
    ExpectEq("wielded offhand", Attacker.getAttacks()[1]["attack type"], "shield attack in list");
}

/////////////////////////////////////////////////////////////////////////////
void GetAttacksReturnDualWieldWeaponsWithAttacks()
{
    object weapon = CreateWeapon("blah");
    object weapon2 = CreateWeapon("stuff");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(weapon2.equip("stuff offhand"), "second weapon equip called");

    ExpectEq(2, sizeof(Attacker.getAttacks()), "2 attacks returned");
    ExpectEq("wielded primary", Attacker.getAttacks()[0]["attack type"], "weapon attack in list");
    ExpectEq("wielded offhand", Attacker.getAttacks()[1]["attack type"], "weapon attack in list");
}

/////////////////////////////////////////////////////////////////////////////
void GetAttacksReturnsExtraAttacksFromServices()
{
    object weapon = CreateWeapon("blah");
    ExpectTrue(weapon.equip("blah"), "weapon equip called");

    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBiological();
    Attacker.ToggleMockBackground();
    ExpectEq(5, sizeof(Attacker.getAttacks()), "5 attacks returned");
}

/////////////////////////////////////////////////////////////////////////////
void GetAttacksReturnsOnlyOneAttackWhenInstrumentWielded()
{
    object instrument =
        clone_object("/lib/instances/items/instruments/strings/lute.c");
    move_object(instrument, Attacker);
    ExpectTrue(instrument.equip("lute"), "instrument equip called");

    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBiological();
    Attacker.ToggleMockBackground();
    ExpectEq(1, sizeof(Attacker.getAttacks()), "1 attack returned");
}

/////////////////////////////////////////////////////////////////////////////
void GetAttacksReturnsBonusAttackWhenInstrumentWieldedAndBonusInPlace()
{
    object instrument =
        clone_object("/lib/instances/items/instruments/strings/lute.c");
    move_object(instrument, Attacker);
    ExpectTrue(instrument.equip("lute"), "instrument equip called");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus sonic attack", 25);
    modifier.set("registration list", ({ Attacker }));

    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBiological();
    Attacker.ToggleMockBackground();
    ExpectEq(2, sizeof(Attacker.getAttacks()), "2 attacks returned");
}

/////////////////////////////////////////////////////////////////////////////
void GetAttacksWhenDualWieldedReturnsHalfExtraWeaponAttacksFromServices()
{
    object weapon = CreateWeapon("blah");
    object weapon2 = CreateWeapon("stuff");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(weapon2.equip("stuff offhand"), "second weapon equip called");

    Attacker.ToggleMockGuilds();
    Attacker.ToggleMockResearch();
    Attacker.ToggleMockTrait();
    Attacker.ToggleMockBiological();
    Attacker.ToggleMockBackground();
    ExpectEq(7, sizeof(Attacker.getAttacks()), "7 attacks returned");
}

/////////////////////////////////////////////////////////////////////////////
void PlayersCanToggleKillList()
{
    destruct(Attacker);
    Attacker = clone_object("/lib/realizations/player");

    ExpectFalse(Attacker.onKillList(), "initial value");
    Attacker.toggleKillList();
    ExpectTrue(Attacker.onKillList(), "first time toggled");
    Attacker.toggleKillList();
    ExpectFalse(Attacker.onKillList(), "second time toggled");
}

/////////////////////////////////////////////////////////////////////////////
void AttackFiresOnAttackEvent()
{
    getService("environment");

    ToggleCallOutBypass();
    object handler = clone_object("/lib/tests/support/events/mockEventSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    string err = catch (ExpectTrue(Attacker.attack(Target), "target attacked"); nolog);
    ExpectEq("*event handler: onAttack called", err, "onAttack event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AttackFiresOnAttackedEvent()
{
    getService("environment");

    ToggleCallOutBypass();
    object handler = clone_object("/lib/tests/support/events/mockEventSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    string err = catch (ExpectTrue(Target.attack(Attacker), "target attacks attacker"); nolog);
    ExpectEq("*event handler: onAttacked called", err, "onAttacked event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AttackInvolvingDeathCreatesCorpseAndDestroysTarget()
{
    object weapon = CreateWeapon("sword");
    Attacker.hitPoints(Attacker.maxHitPoints());
    weapon.set("bonus long sword", 50);
    weapon.equip("sword");

    Target.hitPoints(1);

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 20);

    object *roomItems = all_inventory(Room);
    ExpectEq(2, sizeof(roomItems), "two object are in the room");
    ExpectTrue(member(roomItems, Attacker) > -1, "attacker is in room");
    ExpectTrue(member(roomItems, Target) > -1, "target is in room");

    ExpectTrue(Attacker.attack(Target));

    roomItems = all_inventory(Room);
    ExpectEq(2, sizeof(roomItems), "two object are in the room");
    ExpectTrue(member(roomItems, Attacker) > -1, "attacker is in room");
    ExpectFalse(member(roomItems, Target) > -1, "target is in room");
    ExpectEq("/lib/items/corpse.c", program_name(roomItems[0]));
}

/////////////////////////////////////////////////////////////////////////////
void AttackInvolvingDeathOfPlayerCreatesCorpseButDoesNotDestroyPlayer()
{
    object weapon = CreateWeapon("sword");
    Attacker.hitPoints(1);
    weapon.equip("sword");

    Target.hitPoints(Target.maxHitPoints());

    object *roomItems = all_inventory(Room);
    ExpectEq(2, sizeof(roomItems), "two objects are in the room");
    ExpectTrue(member(roomItems, Attacker) > -1, "attacker is in room");
    ExpectTrue(member(roomItems, Target) > -1, "target is in room");
    ExpectFalse(Attacker.isDead(), "attacker is not dead");

    ExpectTrue(Target.attack(Attacker));

    roomItems = all_inventory(Room);
    ExpectEq(3, sizeof(roomItems), "three objects are in the room");
    ExpectTrue(member(roomItems, Attacker) > -1, "attacker is in room");
    ExpectTrue(member(roomItems, Target) > -1, "target is in room");
    ExpectTrue(Attacker.isDead(), "attacker is now dead");
    ExpectEq("/lib/items/corpse.c", program_name(roomItems[0]));
}

/////////////////////////////////////////////////////////////////////////////
void OnHitFiresWhenLegalHitIsDone()
{
    getService("environment");

    ToggleCallOutBypass();
    object handler = clone_object("/lib/tests/support/events/mockEventSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    string err = catch (ExpectTrue(Attacker.hit(5, "physical"), "attacker hit is called"); nolog);
    ExpectEq("*event handler: onHit called, data: physical 5, caller: /lib/tests/support/services/combatWithMockServices.c", 
        err, "onHit event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void HitAddsCorrectExperience()
{
    Target.hitPoints(Target.maxHitPoints());
    Target.hit(10000, "physical", Attacker);
    ExpectEq(337, Attacker.experience());
}

/////////////////////////////////////////////////////////////////////////////
void OnDeathFiresWhenKillingBlowLands()
{
    getService("environment");

    ToggleCallOutBypass();
    object handler = clone_object("/lib/tests/support/events/onDeathSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    string err = catch (ExpectTrue(Attacker.hit(500, "physical"), "attacker hit is called"); nolog);
    ExpectEq("*event handler: onDeath called: /lib/tests/support/services/combatWithMockServices.c",
        err, "onDeath event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SettingWimpyWorksCorrectly()
{
    clone_object("/lib/tests/support/services/catchShadow.c").beginShadow(Attacker);
    ExpectEq(0, Attacker.Wimpy(), "Wimpy is initially 0");
    ExpectEq(70, Attacker.Wimpy("70"), "A wimpy of 70 can be set");
    ExpectEq(50, Attacker.Wimpy("50"), "A wimpy of 50 can be set");
    ExpectEq(0, Attacker.Wimpy("0"), "A wimpy of 0 can be set");
    ExpectEq(70, Attacker.Wimpy("80"), "A wimpy of 80 caps at 70%");
    ExpectEq(0, Attacker.Wimpy("-10"), "A wimpy of -10 floors at 0%");
}

/////////////////////////////////////////////////////////////////////////////
void WimpyIsNotTriggeredWhenHitPointsAboveThreshhold()
{
    getService("environment");

    ToggleCallOutBypass();
    ExpectEq(50, Attacker.Wimpy("50"), "A wimpy of 50 can be set");

    Attacker.hitPoints(100);
    Target.hitPoints(Target.maxHitPoints());
    Attacker.registerAttacker(Target);

    object handler = clone_object("/lib/tests/support/events/onRunAwaySubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");
    ExpectEq(0, handler.TimesRunAwayEventReceived());

    string err = catch (Attacker.heart_beat(); nolog);
    ExpectEq(0, handler.TimesRunAwayEventReceived());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void WimpyIsTriggeredWhenHitPointsBelowThreshhold()
{
    getService("environment");

    ToggleCallOutBypass();
    ExpectEq(50, Attacker.Wimpy("50"), "A wimpy of 50 can be set");

    object combatRoom = load_object("/lib/tests/support/environment/startingRoom.c");
    move_object(Attacker, combatRoom);
    move_object(Target, combatRoom);

    Attacker.hitPoints(50);
    Target.hitPoints(Target.maxHitPoints());
    Attacker.registerAttacker(Target);

    object handler = clone_object("/lib/tests/support/events/onRunAwaySubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");
    ExpectEq(0, handler.TimesRunAwayEventReceived());

    ExpectEq(combatRoom, environment(Attacker));

    string err = catch (Attacker.heart_beat(); nolog);
    ExpectNotEq(object_name(combatRoom), object_name(environment(Attacker)));
    ExpectEq(1, handler.TimesRunAwayEventReceived());

    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AttackerAttacksDuringHeartBeat()
{
    getService("environment");

    ToggleCallOutBypass();
    Attacker.hitPoints(Attacker.maxHitPoints());
    Target.hitPoints(Target.maxHitPoints());

    Attacker.attack(Target);

    object handler = clone_object("/lib/tests/support/events/onAttackSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered for attacker");

    ExpectEq(0, handler.TimesOnAttackReceived(), "before heart_beat, no onAttack events fired");
    Attacker.heart_beat();
    ExpectEq(1, handler.TimesOnAttackReceived(), "after heart_beat, one onAttack event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void TargetAttackedDuringHeartBeat()
{
    getService("environment");

    ToggleCallOutBypass();
    Attacker.hitPoints(Attacker.maxHitPoints());
    Target.hitPoints(Target.maxHitPoints());

    Attacker.attack(Target);

    object handler = clone_object("/lib/tests/support/events/onAttackedSubscriber");
    ExpectTrue(Target.registerEvent(handler), "event handler registered for attacker");

    string err = catch (Attacker.heart_beat(); nolog);
    ExpectEq("*event handler: onAttacked called: /lib/tests/support/services/testMonster.c",
        err, "onAttacked event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void HeartBeatHealsHitPointsWhenBelowMaxEveryFifthTime()
{
    Attacker.hitPoints(20);
    Attacker.spellPoints(Attacker.maxSpellPoints());
    Attacker.staminaPoints(Attacker.maxStaminaPoints());

    Attacker.heart_beat();
    ExpectEq(23, Attacker.hitPoints(), "3 hit points healed");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus heal hit points", 2);
    modifier.set("registration list", ({ Attacker }));

    for (int i = 0; i < 14; i++)
    {
        Attacker.heart_beat();
        ExpectEq(23, Attacker.hitPoints(), "0 hit points healed");
    }
    Attacker.heart_beat();
    ExpectEq(23, Attacker.hitPoints(), "0 hit points healed");

    Attacker.heart_beat();
    ExpectEq(28, Attacker.hitPoints(), "5 hit points healed");
}

/////////////////////////////////////////////////////////////////////////////
void HeartBeatHealsAtDifferentRatesWhenBonusApplied()
{
    Attacker.hitPoints(20);
    Attacker.spellPoints(Attacker.maxSpellPoints());
    Attacker.staminaPoints(Attacker.maxStaminaPoints());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus heal hit points rate", 26);
    modifier.set("registration list", ({ Attacker }));

    Attacker.heart_beat();
    ExpectEq(23, Attacker.hitPoints(), "3 hit points healed");

    Attacker.heart_beat();
    ExpectEq(23, Attacker.hitPoints(), "0 hit points healed");

    Attacker.heart_beat();
    ExpectEq(23, Attacker.hitPoints(), "0 hit points healed");

    Attacker.heart_beat();
    ExpectEq(26, Attacker.hitPoints(), "3 hit points healed");

    Attacker.heart_beat();
    ExpectEq(26, Attacker.hitPoints(), "0 hit points healed");
}

/////////////////////////////////////////////////////////////////////////////
void HeartBeatHealsSpellPointsWhenBelowMaxEveryFifthTime()
{
    Attacker.hitPoints(Attacker.maxHitPoints());
    Attacker.spellPoints(20);
    Attacker.staminaPoints(Attacker.maxStaminaPoints());

    Attacker.heart_beat();
    ExpectEq(24, Attacker.spellPoints(), "4 spell points healed");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus heal spell points", 2);
    modifier.set("registration list", ({ Attacker }));

    for (int i = 0; i < 14; i++)
    {
        Attacker.heart_beat();
        ExpectEq(24, Attacker.spellPoints(), "0 spell points healed");
    }
    Attacker.heart_beat();
    ExpectEq(24, Attacker.spellPoints(), "0 spell points healed");

    Attacker.heart_beat();
    ExpectEq(30, Attacker.spellPoints(), "6 spell points healed");
}

/////////////////////////////////////////////////////////////////////////////
void HeartBeatHealsSPAtDifferentRatesWhenBonusApplied()
{
    Attacker.hitPoints(Attacker.maxHitPoints());
    Attacker.spellPoints(20);
    Attacker.staminaPoints(Attacker.maxStaminaPoints());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus heal spell points rate", 26);
    modifier.set("registration list", ({ Attacker }));

    Attacker.heart_beat();
    ExpectEq(24, Attacker.spellPoints(), "4 spell points healed");

    Attacker.heart_beat();
    ExpectEq(24, Attacker.spellPoints(), "0 spell points healed");

    Attacker.heart_beat();
    ExpectEq(24, Attacker.spellPoints(), "0 spell points healed");

    Attacker.heart_beat();
    ExpectEq(28, Attacker.spellPoints(), "4 spell points healed");

    Attacker.heart_beat();
    ExpectEq(28, Attacker.spellPoints(), "0 spell points healed");
}

/////////////////////////////////////////////////////////////////////////////
void HeartBeatHealsStaminaPointsWhenBelowMaxEveryFifthTime()
{
    Attacker.hitPoints(Attacker.maxHitPoints());
    Attacker.spellPoints(Attacker.maxSpellPoints());
    Attacker.staminaPoints(20);

    Attacker.heart_beat();
    ExpectEq(24, Attacker.staminaPoints(), "4 stamina points healed");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus heal stamina", 2);
    modifier.set("registration list", ({ Attacker }));

    for (int i = 0; i < 14; i++)
    {
        Attacker.heart_beat();
        ExpectEq(24, Attacker.staminaPoints(), "0 stamina points healed");
    }

    Attacker.heart_beat();
    ExpectEq(24, Attacker.staminaPoints(), "0 stamina points healed");

    Attacker.heart_beat();
    ExpectEq(30, Attacker.staminaPoints(), "6 stamina points healed");
}

/////////////////////////////////////////////////////////////////////////////
void HeartBeatHealsStaminaAtDifferentRatesWhenBonusApplied()
{
    Attacker.hitPoints(Attacker.maxHitPoints());
    Attacker.spellPoints(Attacker.maxSpellPoints());
    Attacker.staminaPoints(20);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus heal stamina rate", 26);
    modifier.set("registration list", ({ Attacker }));

    Attacker.heart_beat();
    ExpectEq(24, Attacker.staminaPoints(), "4 stamina points healed");

    Attacker.heart_beat();
    ExpectEq(24, Attacker.staminaPoints(), "0 stamina points healed");

    Attacker.heart_beat();
    ExpectEq(24, Attacker.staminaPoints(), "0 stamina points healed");

    Attacker.heart_beat();
    ExpectEq(28, Attacker.staminaPoints(), "4 stamina points healed");

    Attacker.heart_beat();
    ExpectEq(28, Attacker.staminaPoints(), "0 stamina points healed");
}

/////////////////////////////////////////////////////////////////////////////
void DamageReflectionIsTriggered()
{
    getService("environment");

    ToggleCallOutBypass();
    Attacker.hitPoints(Attacker.maxHitPoints());
    Target.hitPoints(Target.maxHitPoints());
    Attacker.registerAttacker(Target);
    Target.registerAttacker(Attacker);

    object handler = clone_object("/lib/tests/support/events/mockEventSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    // An onHit event would get triggered if Attacker is hit
    ExpectTrue(Target.hit(25, "physical"), "target hit is called");

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("damage reflection", 15);
    ExpectEq(1, modifier.set("registration list", ({ Target })), "registration list can be set");

    string err = catch (ExpectTrue(Target.hit(25, "physical"), "attack reflected on attacker"); nolog);
    ExpectEq("*event handler: onHit called, data: physical 3, caller: /lib/tests/support/services/combatWithMockServices.c",
        err, "onHit event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SlowDoesNotAttackEveryRound()
{
    getService("environment");

    ToggleCallOutBypass();
    Attacker.hitPoints(Attacker.maxHitPoints());
    Target.hitPoints(Target.maxHitPoints());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("slow", 1);
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");

    Attacker.attack(Target);

    object handler = clone_object("/lib/tests/support/events/onAttackSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered for attacker");

    // Expect that the first call to heart_beat does not initiate an attack
    ExpectEq(0, handler.TimesOnAttackReceived(), "before heart_beat, no onAttack events fired");
    Attacker.heart_beat();
    ExpectEq(0, handler.TimesOnAttackReceived(), "after heart_beat, no onAttack events fired");
    Attacker.heart_beat();
    ExpectEq(1, handler.TimesOnAttackReceived(), "after second heart_beat, one onAttack event fired");
    Attacker.heart_beat();
    ExpectEq(1, handler.TimesOnAttackReceived(), "after third heart_beat, one onAttack event fired");
    Attacker.heart_beat();
    ExpectEq(2, handler.TimesOnAttackReceived(), "after fourth heart_beat, two onAttack event fired");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void HasteAddsAnExtraAttack()
{
    getService("environment");

    ToggleCallOutBypass();
    Attacker.Con(30);
    Attacker.hitPoints(Attacker.maxHitPoints());
    Target.hitPoints(Target.maxHitPoints());

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("haste", 1);
    ExpectEq(1, modifier.set("registration list", ({ Attacker })), "registration list can be set");

    Attacker.attack(Target);

    object handler = clone_object("/lib/tests/support/events/onAttackSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered for attacker");

    ExpectEq(0, handler.TimesOnAttackReceived(), "before heart_beat, no onAttack events fired");
    Attacker.heart_beat();
    ExpectEq(2, handler.TimesOnAttackReceived(), "after heart_beat, two onAttack events fired");
    Attacker.heart_beat();
    ExpectEq(4, handler.TimesOnAttackReceived(), "after second heart_beat, four onAttack event fired");
    Attacker.heart_beat();
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void HitFailsWhenTargetEtherealAndDamageTypeCannotDamageThem()
{
    Target.hitPoints(Target.maxHitPoints());
    ExpectEq(150, Target.hitPoints());
    Target.addTrait("/lib/tests/support/traits/testEtherealTrait.c");

    ExpectFalse(Target.hit(100, "physical", Attacker));
    ExpectEq(150, Target.hitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void HitSucceedsWhenTargetEtherealAndDamageTypeCanDamageThem()
{
    Target.setMaxHitPoints(1000);
    Target.hitPoints(Target.maxHitPoints());
    ExpectEq(1120, Target.hitPoints());
    Target.addTrait("/lib/tests/support/traits/testEtherealTrait.c");

    ExpectTrue(Target.hit(100, "energy", Attacker));
    ExpectEq(1024, Target.hitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void AttackFailsWhenTargetEtherealAndDamageTypeCannotDamageThem()
{
    object weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    Attacker.addSkillPoints(100);
    ExpectTrue(Attacker.advanceSkill("long sword", 20));
    move_object(weapon, Attacker);
    ExpectTrue(weapon.equip("sword"));

    Target.hitPoints(Target.maxHitPoints());
    ExpectEq(150, Target.hitPoints());
    Target.addTrait("/lib/tests/support/traits/testEtherealTrait.c");

    ExpectTrue(Attacker.attack(Target));
    ExpectEq(150, Target.hitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void AttackSucceedsWhenTargetEtherealAndDamageTypeCanDamageThem()
{
    object weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    Attacker.addSkillPoints(100);
    ExpectTrue(Attacker.advanceSkill("long sword", 20));
    weapon.set("material", "galvorn");

    // Need to remove random miss chances
    weapon.set("bonus attack", 200);
    weapon.set("enchantments", (["energy":20]));
    move_object(weapon, Attacker);
    ExpectTrue(weapon.equip("sword"));

    Target.hitPoints(Target.maxHitPoints());
    ExpectTrue(Target.hitPoints() == Target.maxHitPoints());
    Target.addTrait("/lib/tests/support/traits/testEtherealTrait.c");

    ExpectTrue(Attacker.attack(Target));
    ExpectTrue(Target.hitPoints() < Target.maxHitPoints(), "target hit");
}

/////////////////////////////////////////////////////////////////////////////
void AttackSucceedsWhenTargetEtherealAndHasNonWeaponAttackThatCanDamageEthereal()
{
    Target.setMaxHitPoints(1000);
    ExpectTrue(Attacker.addAttack("energy", 50, 500),"add attack");
    Target.hitPoints(Target.maxHitPoints());
    ExpectTrue(Target.hitPoints() == Target.maxHitPoints());
    Target.addTrait("/lib/tests/support/traits/testEtherealTrait.c");

    ExpectTrue(Attacker.attack(Target));
    ExpectTrue(Target.hitPoints() < Target.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void TargetAttacksWhenAttackerReturnsToArea()
{
    getService("environment");

    Target.setMaxHitPoints(1000);
    ToggleCallOutBypass();
    ExpectEq(50, Attacker.Wimpy("50"), "A wimpy of 50 can be set");

    Attacker.hitPoints(80);
    Target.hitPoints(Target.maxHitPoints());
    Attacker.registerAttacker(Target);

    object handler = clone_object("/lib/tests/support/events/onAttackSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered");

    object targetHandler = clone_object("/lib/tests/support/events/onAttackSubscriber");
    ExpectTrue(Target.registerEvent(targetHandler), "event handler registered");

    Attacker.heart_beat();
    Target.heart_beat();

    ExpectEq(1, handler.TimesOnAttackReceived());
    ExpectEq(1, targetHandler.TimesOnAttackReceived());

    move_object(Attacker, this_object());
    Attacker.heart_beat();
    Target.heart_beat();

    ExpectEq(1, handler.TimesOnAttackReceived());
    ExpectEq(1, targetHandler.TimesOnAttackReceived());

    move_object(Attacker, Room);
    Attacker.heart_beat();
    Target.heart_beat();

    ExpectEq(2, handler.TimesOnAttackReceived());
    ExpectEq(2, targetHandler.TimesOnAttackReceived());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMaxHitPoints()
{
    ExpectEq(150, Target.maxHitPoints());
    Target.testMaxHitPoints(500);

    // This should include 500 for the maxHitPoints value and
    // 120 for attribute bonuses
    ExpectEq(620, Target.maxHitPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMaxSpellPoints()
{
    ExpectEq(150, Target.maxSpellPoints());
    Target.testMaxSpellPoints(500);

    // This should include 500 for the maxSpellPoints value and
    // 120 for attribute bonuses
    ExpectEq(620, Target.maxSpellPoints());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMaxStaminaPoints()
{
    ExpectEq(150, Target.maxStaminaPoints());
    Target.testMaxStaminaPoints(500);

    // This should include 500 for the maxStaminaPoints value and
    // 120 for attribute bonuses
    ExpectEq(620, Target.maxStaminaPoints());
}

/////////////////////////////////////////////////////////////////////////////
void DamageResistanceReducesDamageTaken()
{
    Target.setMaxHitPoints(880);
    Target.hitPoints(Target.maxHitPoints());
    ExpectEq(1000, Target.hitPoints());
    ExpectEq(496, Target.hit(500, "fire"));

    Target.hitPoints(Target.maxHitPoints());
    ExpectEq(1000, Target.hitPoints());
    Target.addTrait("/lib/tests/support/traits/testTrait.c");

    ExpectEq(445, Target.hit(500, "fire"));
}

/////////////////////////////////////////////////////////////////////////////
void DamageResistanceWithTraitAndEquipmentReducesDamageTaken()
{
    Target.setMaxHitPoints(880);
    Target.hitPoints(Target.maxHitPoints());
    ExpectEq(1000, Target.hitPoints());
    ExpectEq(496, Target.hit(500, "fire"));

    Target.hitPoints(Target.maxHitPoints());
    ExpectEq(1000, Target.hitPoints());
    Target.addTrait("/lib/tests/support/traits/testTrait.c");
    object weapon = CreateWeapon("sword");
    weapon.set("resistances", ([ "fire": 5 ]));
    move_object(weapon, Target);
    weapon.equip("sword");

    ExpectEq(440, Target.hit(500, "fire"));
}

/////////////////////////////////////////////////////////////////////////////
void HitSubtractsFromManaWhenManaShieldIsActive()
{
    Target.setMaxHitPoints(1000);
    Target.hitPoints(Target.maxHitPoints());
    Target.setMaxSpellPoints(100);
    Target.spellPoints(Target.maxSpellPoints());

    ExpectEq(1120, Target.hitPoints());
    ExpectEq(220, Target.spellPoints());

    Target.addTrait("/lib/tests/support/traits/testManaShieldTrait.c");

    Target.hit(100, "physical", Attacker);
    ExpectEq(1120, Target.hitPoints());
    ExpectEq(124, Target.spellPoints());
}

/////////////////////////////////////////////////////////////////////////////
void DamageTransitionsToHitPointsWhenManaIsDepleted()
{
    Target.setMaxHitPoints(1000);
    Target.hitPoints(Target.maxHitPoints());
    Target.setMaxSpellPoints(100);
    Target.spellPoints(Target.maxSpellPoints());

    ExpectEq(1120, Target.hitPoints());
    ExpectEq(220, Target.spellPoints());

    Target.addTrait("/lib/tests/support/traits/testManaShieldTrait.c");

    Target.hit(500, "physical", Attacker);
    ExpectEq(844, Target.hitPoints());
    ExpectEq(0, Target.spellPoints());
}

/////////////////////////////////////////////////////////////////////////////
void DefensiveStanceCorrectlyApplied()
{
    destruct(Attacker);
    Attacker = clone_object("/lib/tests/support/services/mockPlayer.c");
    Attacker.Name("Bob");
    Attacker.Str(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Int(20);
    Attacker.Wis(20);
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 8);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(5, Attacker.calculateDefendAttack());
    ExpectEq(13, Attacker.calculateAttack(Target, weapon, 1));

    Attacker.addTrait("/lib/tests/support/traits/testDefensiveStanceTrait.c");

    ExpectEq(7, Attacker.calculateDefendAttack());
    ExpectEq(6, Attacker.calculateAttack(Target, weapon, 1));
}

/////////////////////////////////////////////////////////////////////////////
void OffensiveStanceCorrectlyApplied()
{
    destruct(Attacker);
    Attacker = clone_object("/lib/tests/support/services/mockPlayer.c");
    Attacker.Name("Bob");
    Attacker.Str(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Int(20);
    Attacker.Wis(20);
    object weapon = CreateWeapon("blah");

    Attacker.addSkillPoints(100);
    Attacker.advanceSkill("long sword", 8);

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(5, Attacker.calculateDefendAttack());
    ExpectEq(13, Attacker.calculateAttack(Target, weapon, 1));

    Attacker.addTrait("/lib/tests/support/traits/testOffensiveStanceTrait.c");

    ExpectEq(2, Attacker.calculateDefendAttack());
    ExpectEq(19, Attacker.calculateAttack(Target, weapon, 1));
}

/////////////////////////////////////////////////////////////////////////////
void AttackerDoesNotAttackWhenDoNotAttackTraitIsActive()
{
    destruct(Attacker);
    Attacker = clone_object("/lib/tests/support/services/mockPlayer.c");
    Attacker.Name("Bob");
    Attacker.Str(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Int(20);
    Attacker.Wis(20);
    move_object(Attacker, Room);

    getService("environment");

    ToggleCallOutBypass();
    Attacker.hitPoints(Attacker.maxHitPoints());
    Target.hitPoints(Target.maxHitPoints());

    Attacker.attack(Target);

    object handler = clone_object("/lib/tests/support/events/onAttackSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered for attacker");

    ExpectEq(0, handler.TimesOnAttackReceived(), "before heart_beat, no onAttack events fired");
    ExpectEq(0, Attacker.roundsSinceLastAttack());
    ExpectEq(0, Target.roundsSinceLastAttack());

    Attacker.heart_beat();
    ExpectEq(1, handler.TimesOnAttackReceived(), "after heart_beat, one onAttack event fired");
    ExpectEq(0, Attacker.roundsSinceLastAttack());
    ExpectEq(0, Target.roundsSinceLastAttack());

    Attacker.addTrait("/lib/tests/support/traits/testDoNotAttackTrait.c");

    Attacker.heart_beat();
    ExpectEq(1, handler.TimesOnAttackReceived(), "after heart_beat, still one onAttack event fired");
    ExpectEq(1, Attacker.roundsSinceLastAttack());
    ExpectEq(0, Target.roundsSinceLastAttack());

    Attacker.heart_beat();
    ExpectEq(1, handler.TimesOnAttackReceived(), "after heart_beat, still one onAttack event fired");
    ExpectEq(2, Attacker.roundsSinceLastAttack());
    ExpectEq(0, Target.roundsSinceLastAttack());

    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AttackOccursAfterTenRoundsWhileDoNotAttackIsActive()
{
    destruct(Attacker);
    Attacker = clone_object("/lib/tests/support/services/mockPlayer.c");
    Attacker.Name("Bob");
    Attacker.Str(20);
    Attacker.Dex(20);
    Attacker.Con(20);
    Attacker.Int(20);
    Attacker.Wis(20);
    move_object(Attacker, Room);

    getService("environment");

    ToggleCallOutBypass();
    Attacker.hitPoints(Attacker.maxHitPoints());
    Target.hitPoints(Target.maxHitPoints());

    Attacker.attack(Target);

    object handler = clone_object("/lib/tests/support/events/onAttackSubscriber");
    ExpectTrue(Attacker.registerEvent(handler), "event handler registered for attacker");

    Attacker.heart_beat();
    ExpectEq(1, handler.TimesOnAttackReceived(), "after heart_beat, one onAttack event fired");
    ExpectEq(0, Attacker.roundsSinceLastAttack());
    ExpectEq(0, Target.roundsSinceLastAttack());

    Attacker.addTrait("/lib/tests/support/traits/testDoNotAttackTrait.c");

    Attacker.heart_beat();
    Attacker.heart_beat();
    Attacker.heart_beat();
    Attacker.heart_beat();
    Attacker.heart_beat();
    Attacker.heart_beat();
    Attacker.heart_beat();
    Attacker.heart_beat();
    Attacker.heart_beat();
    Attacker.heart_beat();
    ExpectEq(1, handler.TimesOnAttackReceived(), "after heart_beat, still one onAttack event fired");
    ExpectEq(10, Attacker.roundsSinceLastAttack());
    ExpectEq(0, Target.roundsSinceLastAttack());

    Attacker.heart_beat();
    ExpectEq(2, handler.TimesOnAttackReceived(), "after heart_beat, still one onAttack event fired");
    ExpectEq(0, Attacker.roundsSinceLastAttack());
    ExpectEq(0, Target.roundsSinceLastAttack());
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SupercedeAttackersPlacesNewFoeAtTopOfList()
{
    Attacker.registerAttacker(Target);
    Target.registerAttacker(Attacker);

    object newAttacker = 
        clone_object("/lib/tests/support/services/mockPlayer.c");
    newAttacker.Name("Norman");
    move_object(newAttacker, Room);

    newAttacker.registerAttacker(Target);
    Target.registerAttacker(newAttacker);

    ExpectEq(Attacker, Target.getTargetToAttack(1));

    Target.supercedeAttackers(newAttacker);
    ExpectEq(newAttacker, Target.getTargetToAttack());
}

/////////////////////////////////////////////////////////////////////////////
void CombatDelayAndSpellActionWork()
{
    ExpectEq(0, Attacker.combatDelay(), "Initial combatDelay is 0");
    ExpectEq(0, Attacker.spellAction(), "Initial spellAction is 0");

    Attacker.combatDelay(3);
    ExpectEq(3, Attacker.combatDelay(), "combatDelay increments");

    Attacker.combatDelay(2);
    ExpectEq(5, Attacker.combatDelay(), "combatDelay increments again");

    Attacker.spellAction(4);
    ExpectEq(4, Attacker.spellAction(), "spellAction increments");

    Attacker.spellAction(1);
    ExpectEq(5, Attacker.spellAction(), "spellAction increments again");
}

/////////////////////////////////////////////////////////////////////////////
void GetHostileListReturnsCorrectString()
{
    // No attackers
    ExpectEq("Nothing at all, aren't you lucky?", Attacker.getHostileList());

    // Add one attacker
    Attacker.registerAttacker(Target);
    string list = Attacker.getHostileList();
    ExpectTrue(sizeof(list) > 0, "Hostile list is not empty");
    ExpectTrue(sizeof(regexp(({ list }), "Nukulevee")) > 0, "Contains target's name");
}

/////////////////////////////////////////////////////////////////////////////
void UnregisterAttackerAndStopFightWork()
{
    Attacker.registerAttacker(Target);
    ExpectTrue(Attacker.isInCombatWith(Target), "Attacker is in combat with Target");

    Attacker.unregisterAttacker(Target);
    ExpectFalse(Attacker.isInCombatWith(Target), "Attacker is not in combat with Target");

    Attacker.registerAttacker(Target);
    Attacker.stopFight(Target);
    ExpectFalse(Attacker.isInCombatWith(Target), "stopFight removes attacker");
}

/////////////////////////////////////////////////////////////////////////////
void ConfigurePVPSettingWorks()
{
    destruct(Attacker);
    Attacker = clone_object("/lib/realizations/player");
    move_object(Attacker, Room);

    // Should enable PVP
    Attacker.configurePVPSetting();
    ExpectTrue(Attacker.onKillList(), "PVP enabled");

    // Should not disable PVP
    Attacker.configurePVPSetting();
    ExpectTrue(Attacker.onKillList(), "PVP still enabled");
}

/////////////////////////////////////////////////////////////////////////////
void MaxHitPointsRecalculatesWhenAttributeChanges()
{
    int original = Attacker.maxHitPoints();

    // Change a stat that affects maxHitPoints
    Attacker.Con(Attacker.Con() + 10);

    // Should immediately reflect the new value (cache was reset)
    int recalculated = Attacker.maxHitPoints();
    ExpectTrue(recalculated > original, "maxHitPoints recalculates after Con changes");
}

/////////////////////////////////////////////////////////////////////////////
void ResetCombatCacheActuallyClearsCache()
{
    ToggleCallOutBypass();
    object subscriber = clone_object("/lib/tests/support/events/resetCacheSubscriber.c");
    Attacker.registerEvent(subscriber);

    ExpectEq(0, subscriber.TimesResetCacheEventReceived(),
        "No reset cache event received before reset");

    // Change a stat that triggers a recalculation
    Attacker.Con(Attacker.Con() + 10);

    ExpectEq(1, subscriber.TimesResetCacheEventReceived(),
        "Reset cache event received after reset");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void VitalsAndSingleLineVitalsReturnStrings()
{
    string vitals = Attacker.vitals();
    string singleLine = Attacker.singleLineVitals();
    ExpectTrue(stringp(vitals) && sizeof(vitals) > 0, "vitals returns a string");
    ExpectTrue(stringp(singleLine) && sizeof(singleLine) > 0, "singleLineVitals returns a string");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponAttacksExecuteWhenNoWeaponAttacksTraitNotPresent()
{
    ToggleCallOutBypass();

    SetUpAttacker(1);
    object weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    weapon->set("bonus attack", 200);
    move_object(weapon, Attacker);
    ExpectTrue(weapon->equip("long sword"));

    Target->setMaxHitPoints(1000);
    Target->hitPoints(Target->maxHitPoints());

    object subscriber = clone_object("/lib/tests/support/events/onHitSubscriber");
    Target->registerEvent(subscriber);

    move_object(Attacker, Room);
    move_object(Target, Room);

    ExpectTrue(Attacker->attack(Target));
    ExpectTrue(subscriber->TimesOnHitEventReceived() > 0,
        "weapon attack should have triggered hit event");

    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void WeaponAttacksSkippedWhenNoWeaponAttacksTraitPresent()
{
    ToggleCallOutBypass();

    SetUpAttacker(1);
    object weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    weapon->set("bonus attack", 200);
    move_object(weapon, Attacker);
    ExpectTrue(weapon->equip("long sword"));

    Attacker->addTrait("/lib/tests/support/traits/noAttackTrait.c");

    Target->setMaxHitPoints(1000);
    Target->hitPoints(Target->maxHitPoints());

    object subscriber = clone_object("/lib/tests/support/events/onHitSubscriber");
    Target->registerEvent(subscriber);

    move_object(Attacker, Room);
    move_object(Target, Room);

    ExpectTrue(Attacker->attack(Target));
    ExpectEq(0, subscriber->TimesOnHitEventReceived(),
        "no hit events should occur when no weapon attacks trait is present");

    ToggleCallOutBypass();
}
