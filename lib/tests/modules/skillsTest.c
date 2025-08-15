//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Skills;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    getService("environment");

    ToggleCallOutBypass();
    Skills = clone_object("/lib/tests/support/services/skillsWithMockServices");
    Skills.Name("Bob");
    Skills.Str(20);
    Skills.Dex(20);
    Skills.Con(20);
    Skills.Int(20);
    Skills.Wis(20);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Skills);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AddSkillPointsCorrectlyAddsSkillPoints()
{
    ExpectEq(0, Skills.AvailableSkillPoints(), "available skill points are initially 0");
    ExpectEq(10, Skills.addSkillPoints(10), "10 skill points added");
    ExpectEq(10, Skills.AvailableSkillPoints(), "available skill points are 10");
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillCostReturnsCorrectCost()
{
    ExpectEq(2, Skills.advanceSkillCost("long sword", 1), "Cost to advance long sword is 2 points");
    ExpectEq(2, Skills.advanceSkillCost("reading", 1), "Cost to advance reading is 2 points");
    ExpectEq(0, Skills.advanceSkillCost("weaselclaw", 1), "Cost to advance invalid skill is 0 points");
    ExpectEq(10, Skills.advanceSkillCost("long sword", 5), "Cost to advance long sword is 10 points");
}

/////////////////////////////////////////////////////////////////////////////
void CannotAdvanceSkillsIfNotEnoughPointsToSpend()
{
    ExpectFalse(Skills.advanceSkill("long sword", 1), "cannot advance without available points");
    ExpectEq(0, Skills.getSkill("long sword"), "skill is set to 0");
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillsIfEnoughPointsAvailable()
{
    ExpectEq(10, Skills.addSkillPoints(10), "10 skill points added");
    ExpectTrue(Skills.advanceSkill("long sword", 2), "can advance");
    ExpectEq(2, Skills.getSkill("long sword"), "skill is set to 2");
}

/////////////////////////////////////////////////////////////////////////////
void AvailableSkillPointsReturnsCorrectValue()
{
    ExpectEq(0, Skills.AvailableSkillPoints(), "available skill points are initially 0");
    ExpectEq(10, Skills.addSkillPoints(10), "10 skill points added");
    ExpectEq(10, Skills.AvailableSkillPoints(), "available skill points are 10");
    ExpectTrue(Skills.advanceSkill("long sword", 2), "can advance");
    ExpectEq(6, Skills.AvailableSkillPoints(), "6 skill points available");
    ExpectEq(2, Skills.getSkill("long sword"), "skill is set to 0");
}

/////////////////////////////////////////////////////////////////////////////
void DecrementSkillReturnsCorrectValue()
{
    ExpectEq(10, Skills.addSkillPoints(10), "10 skill points added");
    ExpectTrue(Skills.advanceSkill("long sword", 2), "can advance");
    ExpectEq(2, Skills.getSkill("long sword"), "skill is set to 2");
    ExpectEq(6, Skills.AvailableSkillPoints(), "6 skill points available");
    ExpectTrue(Skills.decrementSkill("long sword", 1), "can advance");
    ExpectEq(8, Skills.AvailableSkillPoints(), "6 skill points available");
    ExpectEq(1, Skills.getSkill("long sword"), "skill is set to 1");
}

/////////////////////////////////////////////////////////////////////////////
void GetSkillIsModifiedByInventory()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("encumberance", 2);
    weapon.set("material", "steel");
    weapon.set("weapon type", "long sword");
    weapon.set("bonus long sword", 1);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Skills);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("encumberance", 5);
    armor.set("material", "steel");
    armor.set("bonus long sword", 2);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Skills);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus long sword", 3);

    ExpectEq(10, Skills.addSkillPoints(10), "10 skill points added");
    ExpectTrue(Skills.advanceSkill("long sword", 2), "can advance");

    ExpectEq(2, Skills.getSkill("long sword"), "skill is initially 2");
    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectEq(3, Skills.getSkill("long sword"), "skill is 3 with weapon");
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(5, Skills.getSkill("long sword"), "skill is 5 with weapon and armor");
    ExpectEq(1, modifier.set("registration list", ({ Skills })), "registration list can be set");
    ExpectEq(8, Skills.getSkill("long sword"), "skill is 8");
}

/////////////////////////////////////////////////////////////////////////////
void GetSkillIsModifiedByServices()
{
    ExpectEq(10, Skills.addSkillPoints(10), "10 skill points added");
    ExpectTrue(Skills.advanceSkill("long sword", 2), "can advance");
    Skills.ToggleMockResearch();
    ExpectEq(4, Skills.getSkill("long sword"), "skill is 4");
    Skills.ToggleMockTrait();
    ExpectEq(6, Skills.getSkill("long sword"), "skill is 6");
    Skills.ToggleMockBackground();
    ExpectEq(8, Skills.getSkill("long sword"), "skill is 8");
    Skills.Race("high elf");
    ExpectEq(13, Skills.getSkill("long sword"), "skill is 13");
}

/////////////////////////////////////////////////////////////////////////////
void GetSkillDoesNotModifyUntrainedSkillsForResearchInventoryOrEnvironment()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("encumberance", 2);
    weapon.set("material", "steel");
    weapon.set("weapon type", "long sword");
    weapon.set("bonus long sword", 1);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Skills);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("encumberance", 5);
    armor.set("material", "steel");
    armor.set("bonus long sword", 2);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Skills);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus long sword", 3);
    Skills.ToggleMockResearch();

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Skills })), "registration list can be set");
    ExpectEq(0, Skills.getSkill("long sword"), "skill is 0");
}

/////////////////////////////////////////////////////////////////////////////
void GetSkillDoesModifyUntrainedSkillsForRaceTraitsAndBackground()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("encumberance", 2);
    weapon.set("material", "steel");
    weapon.set("weapon type", "long sword");
    weapon.set("bonus long sword", 1);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Skills);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("encumberance", 5);
    armor.set("material", "steel");
    armor.set("bonus long sword", 2);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Skills);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus long sword", 3);

    ExpectEq(0, Skills.getSkill("long sword"), "initial skill");

    Skills.ToggleMockResearch();
    ExpectEq(0, Skills.getSkill("long sword"), "research does not add");

    Skills.ToggleMockTrait();
    ExpectEq(2, Skills.getSkill("long sword"), "traits add");

    Skills.ToggleMockBackground();
    ExpectEq(4, Skills.getSkill("long sword"), "background adds");

    Skills.Race("high elf");
    ExpectEq(9, Skills.getSkill("long sword"), "race adds");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Skills })), "registration list can be set");
    ExpectEq(9, Skills.getSkill("long sword"), "equipment does not add");
}
/////////////////////////////////////////////////////////////////////////////
void GetSkillModifierReturnsCorrectValue()
{
    ExpectEq(10, Skills.addSkillPoints(10), "10 skill points added");
    ExpectTrue(Skills.advanceSkill("long sword", 2), "can advance");
    ExpectEq(2, Skills.getSkillModifier("long sword"), "skill modifier is 2");
}

/////////////////////////////////////////////////////////////////////////////
void UntrainedSkillReturnsPenaltyForGetSkillModifier()
{
    ExpectEq(-10, Skills.getSkillModifier("long sword"), "skill modifier is -10");
}

/////////////////////////////////////////////////////////////////////////////
void GetSkillModifierUsesInventoryAndServices()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("encumberance", 2);
    weapon.set("material", "steel");
    weapon.set("weapon type", "long sword");
    weapon.set("bonus long sword", 1);
    weapon.set("equipment locations", OnehandedWeapon);
    move_object(weapon, Skills);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("encumberance", 5);
    armor.set("material", "steel");
    armor.set("bonus long sword", 2);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", Armor);
    move_object(armor, Skills);

    object modifier = clone_object("/lib/items/modifierObject");
    modifier.set("fully qualified name", "blah");
    modifier.set("bonus long sword", 3);
    Skills.ToggleMockResearch();
    Skills.ToggleMockTrait();
    Skills.ToggleMockBackground();
    Skills.Race("high elf");

    ExpectEq(10, Skills.addSkillPoints(10), "10 skill points added");
    ExpectTrue(Skills.advanceSkill("long sword", 2), "can advance");

    ExpectTrue(weapon.equip("blah"), "weapon equip called");
    ExpectTrue(armor.equip("stuff"), "armor equip called");
    ExpectEq(1, modifier.set("registration list", ({ Skills })), "registration list can be set");
    ExpectEq(11, Skills.getSkillModifier("long sword"), "skill modifier is 11");
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillFiresOnSkillAdvancedEventToSubscriber()
{
    Skills.addSkillPoints(100);
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Skills.registerEvent(subscriber);

    string expected = "*event handler: onSkillAdvanced called, data: long sword, caller: /lib/tests/support/services/skillsWithMockServices.c";
    string err = catch (Skills.advanceSkill("long sword", 2); nolog);
    ExpectEq(expected, err, "onSkillAdvanced called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceSkillFiresOnSkillPointsUsedEventToSubscriber()
{
    Skills.addSkillPoints(100);
    object subscriber = clone_object("/lib/tests/support/events/onSkillPointsUsedSubscriber");
    Skills.registerEvent(subscriber);

    string expected = "*event handler: onSkillPointsUsed called, data: 4, caller: /lib/tests/support/services/skillsWithMockServices.c";
    string err = catch (Skills.advanceSkill("long sword", 2); nolog);
    ExpectEq(expected, err, "onSkillPointsUsed called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DecrementSkillFiresOnSkillDecreasedEventToSubscriber()
{
    Skills.addSkillPoints(100);
    Skills.advanceSkill("long sword", 5);
    object subscriber = clone_object("/lib/tests/support/events/mockEventSubscriber");
    Skills.registerEvent(subscriber);

    string expected = "*event handler: onSkillDecreased called, data: long sword, caller: /lib/tests/support/services/skillsWithMockServices.c";
    string err = catch (Skills.decrementSkill("long sword", 2); nolog);
    ExpectEq(expected, err, "onSkillDecreased called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void DecrementSkillFiresOnSkillPointsIncreasedEventToSubscriber()
{
    Skills.addSkillPoints(100);
    Skills.advanceSkill("long sword", 5);
    object subscriber = clone_object("/lib/tests/support/events/onSkillPointsIncreasedSubscriber");
    Skills.registerEvent(subscriber);

    string expected = "*event handler: onSkillPointsIncreased called, data: 4, caller: /lib/tests/support/services/skillsWithMockServices.c";
    string err = catch (Skills.decrementSkill("long sword", 2); nolog);
    ExpectEq(expected, err, "onSkillPointsIncreased called on subscriber");
}

/////////////////////////////////////////////////////////////////////////////
void AddSkillPointsFiresOnSkillPointsIncreasedEventToSubscriber()
{
    object subscriber = clone_object("/lib/tests/support/events/onSkillPointsIncreasedSubscriber");
    Skills.registerEvent(subscriber);

    string expected = "*event handler: onSkillPointsIncreased called, data: 100, caller: /lib/tests/support/services/skillsWithMockServices.c";
    string err = catch (Skills.addSkillPoints(100); nolog);
    ExpectEq(expected, err, "onSkillPointsIncreased called on subscriber");
}
