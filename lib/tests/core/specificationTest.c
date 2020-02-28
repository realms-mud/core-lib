//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Specification;
object Attacker;
object Configuration;
string colorConfiguration;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    load_object("/lib/dictionaries/guildsDictionary.c");
    load_object("/lib/tests/support/guilds/testGuild.c");

    colorConfiguration = "3-bit";
    Configuration = load_object("/lib/dictionaries/configurationDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Specification = clone_object("/lib/tests/support/research/testSpecification");
    Attacker = clone_object("/lib/tests/support/services/combatWithMockServices");
    Attacker->Name("Earl");
    Attacker->Str(20);
    Attacker->Int(20);
    Attacker->Dex(20);
    Attacker->Con(20);
    Attacker->Wis(20);
    Attacker->Chr(20);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Specification);
    destruct(Attacker);
}

/////////////////////////////////////////////////////////////////////////////
void CanSetNameForSpecification()
{
    ExpectTrue(Specification->addSpecification("name", "research name"), "set the research name");
    ExpectEq("research name", Specification->query("name"), "query the research name");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidNameThrowsError()
{
    string err = catch (Specification->addSpecification("name", 2));
    string expectedError = "*ERROR - specification: The 'name' value must be a string.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetDescriptionForSpecification()
{
    ExpectTrue(Specification->addSpecification("description", "research description"), "set the research description");
    ExpectEq("research description", Specification->query("description"), "query the research description");
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidDescriptionThrowsError()
{
    string err = catch (Specification->addSpecification("description", 2));
    string expectedError = "*ERROR - specification: The 'description' value must be a string.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid descriptions");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidLimitedByValue()
{
    string err = catch (Specification->addSpecification("limited by", ([ ])));
    string expectedError = "*ERROR - specification: The value of 'limited by' must be a valid limiting mapping. See the specification.validLimitor method for details.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid 'limited by'");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetInvalidLimitedByKey()
{
    string err = catch (Specification->addSpecification("limited by", (["blarg": 2])));
    string expectedError = "*ERROR - specification: The value of 'limited by' must be a valid limiting mapping. See the specification.validLimitor method for details.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid 'limited by'");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForOpponentRace()
{
    mapping limitor = (["opponent race":"elf"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForOpponentCreatureRace()
{
    mapping limitor = (["opponent race":"ogre"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetLimitorForInvalidRace()
{
    string err = catch (Specification->addSpecification("limited by", (["opponent race":"tomato"])));
    string expectedError = "*ERROR - specification: The value of 'limited by' must be a valid limiting mapping. See the specification.validLimitor method for details.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid 'limited by'");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForOpponentGuild()
{
    mapping limitor = (["opponent guild":"test"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CannotSetLimitorForInvalidGuild()
{
    string err = catch (Specification->addSpecification("limited by", (["opponent guild":"turnip"])));
    string expectedError = "*ERROR - specification: The value of 'limited by' must be a valid limiting mapping. See the specification.validLimitor method for details.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid 'limited by'");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForOpponentFaction()
{
    mapping limitor = (["opponent faction":"/lib/tests/support/factions/goodGuys.c"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForEnvironment()
{
    mapping limitor = (["environment":"forest"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForIntoxication()
{
    mapping limitor = (["intoxicated":1]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForDrugged()
{
    mapping limitor = (["drugged":1]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForNearDeath()
{
    mapping limitor = (["near death":10]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForStaminaDrained()
{
    mapping limitor = (["stamina drained":10]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForSpellPointsDrained()
{
    mapping limitor = (["spell points drained":1]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForEquipmentThatIsAValidWeaponType()
{
    mapping limitor = (["equipment":"long sword"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForEquipmentThatIsAValidArmorType()
{
    mapping limitor = (["equipment":"soft leather"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForEquipmentThatIsAValidEquipmentType()
{
    mapping limitor = (["equipment":"gloves"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorForEquipmentThatIsValidListType()
{
    mapping limitor = (["equipment":({ "long sword", "short sword" }) ]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetLimitorThatIsAList()
{
    mapping limitor = ([
        "crafting type":({ "sword", "dagger", "pole arm", "staff",
                           "axe", "hammer", "mace", "flail", "crossbow",
                           "bow", "sling", "thrown", "shield" })
    ]);

    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetMultipleLimitors()
{
    mapping limitor = (["spell points drained":1, "opponent guild":"test"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq(limitor, Specification->query("limited by"), "query the limitor");
}

/////////////////////////////////////////////////////////////////////////////
void EffectIsLimitedReturnsCorrectValue()
{
    mapping limitor = (["intoxicated":1, "opponent guild": "test"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectTrue(Specification->EffectIsLimited(), "the research is limited");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueIfNoLimitorsArePresent()
{
    ExpectTrue(Specification->canApplySkill("name", Attacker, Attacker));
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForOpponentRace()
{
    mapping limitor = (["opponent race":"elf"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    Attacker->Race("elf");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForOpponentGuild()
{
    mapping limitor = (["opponent guild":"test"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    Attacker->ToggleMockGuilds();
    Attacker->SetGuild("test");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForOpponentFaction()
{
    mapping limitor = (["opponent faction":"/lib/tests/support/factions/goodGuys.c"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    Attacker->ToggleMockFaction();
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForEnvironment()
{
    object room = clone_object("/lib/environment/environment");

    mapping limitor = (["environment":"unknown"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");
    move_object(Attacker, room);

    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForIntoxication()
{
    mapping limitor = (["intoxicated":1]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    Attacker->ToggleMockBiological();
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForDrugged()
{
    mapping limitor = (["drugged":1]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    Attacker->ToggleMockBiological();
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForNearDeath()
{
    mapping limitor = (["near death":50]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");

    Attacker->hitPoints(20);
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");

    Attacker->hitPoints(Attacker->maxHitPoints());
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForWeapon()
{
    mapping limitor = (["equipment":"long sword"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attacker);

    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForWeaponInList()
{
    mapping limitor = (["equipment":({ "long sword", "short sword" })]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attacker);

    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");

    weapon->set("weapon type", "short sword");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");

    weapon->set("weapon type", "axe");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsFalseWithLimitorForWeaponNotMet()
{
    mapping limitor = (["equipment":"long sword"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "axe");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attacker);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsFalseWithMultipleLimitorForWeaponNotMet()
{
    mapping limitor = (["equipment":({ "long sword", "short sword" })]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "axe");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, Attacker);

    ExpectTrue(weapon->equip("blah"), "weapon equip called");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForArmor()
{
    mapping limitor = (["equipment":"chainmail"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, Attacker);

    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
    ExpectTrue(armor->equip("blah"), "armor equip called");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForEquipment()
{
    mapping limitor = (["equipment":"gloves"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "no values set");

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("armor type", "soft leather");
    armor->set("equipment locations", Gloves);
    move_object(armor, Attacker);

    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
    ExpectTrue(armor->equip("blah"), "glove equip called");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForStaminaDrained()
{
    mapping limitor = (["stamina drained":50]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");

    Attacker->staminaPoints(20);
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");

    Attacker->staminaPoints(Attacker->maxStaminaPoints());
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForSpellPointsDrained()
{
    mapping limitor = (["spell points drained":50]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");

    Attacker->spellPoints(20);
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");

    Attacker->spellPoints(Attacker->maxSpellPoints());
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForOpponentRace()
{
    mapping limitor = (["opponent race":"elf"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when opponent race is elf.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void  DisplayLimitersStringCorrectWithLimitorForOpponentGuild()
{
    mapping limitor = (["opponent guild":"test"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when opponent guild is test.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void  DisplayLimitersStringCorrectWithLimitorForOpponentFaction()
{
    mapping limitor = (["opponent faction":"/lib/tests/support/factions/goodGuys.c"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when opponent faction is good guys.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void  DisplayLimitersStringCorrectWithLimitorForEnvironment()
{
    mapping limitor = (["environment":"forest"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when environment is forest.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForIntoxication()
{
    mapping limitor = (["intoxicated":1]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when you are intoxicated.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForDrugged()
{
    mapping limitor = (["drugged":1]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when you are drugged.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForNearDeath()
{
    mapping limitor = (["near death":50]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when you are near death.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForWeapon()
{
    mapping limitor = (["equipment":"long sword"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when you're using: long sword.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitorsCorrectWithMultipleCraftingItems()
{
    mapping limitor = ([
        "crafting type":({ "sword", "dagger", "pole arm", "staff",
                           "axe", "hammer", "mace", "flail", "crossbow",
                           "bow", "sling", "thrown", "shield" })
    ]);

    ExpectTrue(Specification->addSpecification("limited by", limitor), 
        "set the limitor");

    ExpectEq("\x1b[0;36mThis is only applied when crafting type is one of axe, "
        "bow, crossbow, dagger,\nflail, hammer, mace, pole arm, shield, sling, "
        "staff, sword, or thrown.\n\x1b[0m", 
        Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForWeaponInList()
{
    mapping limitor = (["equipment":({ "long sword", "short sword" })]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when you're using: long sword or short sword.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForStaminaDrained()
{
    mapping limitor = (["stamina drained":50]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when you are stamina drained.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForSpellPointsDrained()
{
    mapping limitor = (["spell points drained":50]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when you are spell points drained.\n\x1b[0m", Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void LimitorsFallBackToSkillWhenInCorrectSubType()
{
    mapping limitor = ([ "crafting type": "hard leather" ]);

    ExpectTrue(Specification->addSpecification("limited by", limitor),
        "set the limitor");

    object chainmail = clone_object("/lib/instances/items/armor/medium-armor/chainmail.c");
    ExpectFalse(Specification->canApplySkill("x", Attacker, chainmail));

    limitor = ([ "crafting type": "chainmail" ]);
    ExpectTrue(Specification->addSpecification("limited by", limitor),
        "set the limitor");
    ExpectTrue(Specification->canApplySkill("x", Attacker, chainmail));

    destruct(chainmail);
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForTimeOfDay()
{
    mapping limitor = (["time of day": "dusk"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");

    object environmentDictionary = 
        load_object("/lib/dictionaries/environmentDictionary.c");

    environmentDictionary->timeOfDay("dusk");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");

    environmentDictionary->timeOfDay("noon");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForSeason()
{
    mapping limitor = (["season": "autumn"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");

    object environmentDictionary =
        load_object("/lib/dictionaries/environmentDictionary.c");

    environmentDictionary->season("autumn");
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");

    environmentDictionary->season("spring");
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void CanApplySkillReturnsTrueWithLimitorForMoonPhase()
{
    mapping limitor = (["moon phase": "waning gibbous"]);
    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");

    object environmentDictionary =
        load_object("/lib/dictionaries/environmentDictionary.c");

    environmentDictionary->setDay(17);
    ExpectTrue(Specification->canApplySkill("blah", Attacker, Attacker), "limitors met");

    environmentDictionary->setDay(24);
    ExpectFalse(Specification->canApplySkill("blah", Attacker, Attacker), "limitors not met");
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForTimeOfDay()
{
    mapping limitor = (["time of day":"dusk"]);

    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when time of day is dusk.\n\x1b[0m", 
        Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForListOfTimesOfDay()
{
    mapping limitor = (["time of day":({ "dawn", "dusk" })]);

    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when time of day is dawn or dusk.\n\x1b[0m",
        Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForSeason()
{
    mapping limitor = (["season":"autumn"]);

    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when season is autumn.\n\x1b[0m",
        Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForListOfSeasons()
{
    mapping limitor = (["season":({ "summer", "autumn" })]);

    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when season is autumn or summer.\n\x1b[0m",
        Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForMoonPhase()
{
    mapping limitor = (["moon phase":"waning gibbous"]);

    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when moon phase is waning gibbous.\n\x1b[0m",
        Specification->displayLimiters(colorConfiguration, Configuration));
}

/////////////////////////////////////////////////////////////////////////////
void DisplayLimitersStringCorrectWithLimitorForListOfMoonPhases()
{
    mapping limitor = (["moon phase":({ "waning gibbous", "waning crescent", "new moon" })]);

    ExpectTrue(Specification->addSpecification("limited by", limitor), "set the limitor");
    ExpectEq("\x1b[0;36mThis is only applied when moon phase is one of new moon, "
        "waning crescent, or\nwaning gibbous.\n\x1b[0m",
        Specification->displayLimiters(colorConfiguration, Configuration));
}
