//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    load_object("/lib/dictionaries/guildsDictionary.c");
    load_object("/lib/tests/support/guilds/mageGuild.c");
    load_object("/lib/tests/support/guilds/fighterGuild.c");

    setRestoreCaller(this_object());
    object database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    database.PrepDatabase();

    object dataAccess = clone_object("/lib/modules/secure/dataAccess.c");
    mapping actor = database.Gorthaur();
    actor["name"] = "rob";
    dataAccess.savePlayerData(actor);

    destruct(dataAccess);
    destruct(database);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("rob");
    Player.hitPoints(30);
    Player.spellPoints(30);
    Player.staminaPoints(30);
    Player.Str(10);
    Player.Int(10);
    Player.Dex(10);
    Player.Wis(10);
    Player.Con(10);
    Player.Chr(10);
    Player.addCommands();
    Player.Race("high elf");
    Player.addTrait("/lib/instances/traits/racial/hillgarathElf.c");
    Player.addTrait("/lib/instances/traits/genetic/smart.c");
    Player.spellPoints(Player.maxSpellPoints());
    Player.staminaPoints(Player.maxStaminaPoints());

    Player.joinGuild("fake mage");
    Player.addExperience(1700);
    Player.advanceLevel("fake mage");

    Player.joinGuild("fake fighter");
    Player.addExperience(2000);

    move_object(Player, load_object("/lib/tests/support/environment/fakeEnvironment.c"));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteScoreCommand()
{
    ExpectTrue(Player.executeCommand("score"));
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteScoreAsQuestionmark()
{
    ExpectTrue(Player.executeCommand("?"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player.executeCommand("scoreblah"));
    ExpectFalse(Player.executeCommand("ascored"));
    ExpectFalse(Player.executeCommand("blah?"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfInvalidFlagsPassed()
{
    ExpectFalse(Player.executeCommand("score -t"));
    ExpectFalse(Player.executeCommand("score -com"));
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysCorrectInformationWithWeaponEquipped()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    command("equip blah", Player);

    ExpectTrue(Player.executeCommand("score"));
    ExpectEq("\x1b[0;32mRob the title-less\n"
        "\x1b[0m\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mRace: \x1b[0m\x1b[0;32mHigh elf (Hillgarathi elf)       \x1b[0m\x1b[0;36mOverall Level: \x1b[0m\x1b[0;32m3                    \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36m  Hit Points: \x1b[0m\x1b[0;35;1m==\x1b[0m\x1b[0;31m........ \x1b[0m\x1b[0;36mSpell Points: \x1b[0m\x1b[0;35;1m==========\x1b[0m\x1b[0;31m \x1b[0m\x1b[0;36m     Stamina: \x1b[0m\x1b[0;35;1m==========\x1b[0m\x1b[0;31m \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;33m              30/121  \x1b[0m\x1b[0;33m                 152/152  \x1b[0m\x1b[0;33m                96/96      \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36m    Strength: \x1b[0m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0;36mIntelligence: \x1b[0m\x1b[0;33;1m14    \x1b[0m\x1b[0;34;1m(+4) \x1b[0m\x1b[0;36m      Wisdom: \x1b[0m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36m   Dexterity: \x1b[0m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m\x1b[0;36mConstitution: \x1b[0m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0;36m    Charisma: \x1b[0m\x1b[0;33;1m12    \x1b[0m\x1b[0;34;1m(+2) \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mGuild: \x1b[0m\x1b[0;33mFake fighter (Neophyte)     \x1b[0m\x1b[0;36mLevel: \x1b[0m\x1b[0;33m1          \x1b[0m\x1b[0;36mExperience: \x1b[0m\x1b[0;35;1m======\x1b[0m\x1b[0;31m....\x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mGuild: \x1b[0m\x1b[0;33mFake mage                   \x1b[0m\x1b[0;36mLevel: \x1b[0m\x1b[0;33m2          \x1b[0m\x1b[0;36mExperience: \x1b[0m\x1b[0;33;1m Level up \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mPrimary Weapon: \x1b[0m\x1b[0;33mSword of Bla...\x1b[0m\x1b[0;36m Attack: \x1b[0m\x1b[0;33m-20 to 80  \x1b[0m\x1b[0;36m      Damage: \x1b[0m\x1b[0;33m  9 to 12 \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36m Defend Attack: \x1b[0m\x1b[0;33m  0 to 0   \x1b[0m\x1b[0;36m       Soak: \x1b[0m\x1b[0;33m  0 to 0   \x1b[0m\x1b[0;36mEncumberance: \x1b[0m\x1b[0;33m  3       \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36m         Wimpy: \x1b[0m\x1b[0;33m  0%\x1b[0m\x1b[0;36m         Hunted by: \x1b[0m\x1b[0;33mNothing at all, aren't you lucky?  \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mYou are normal.  (Yeah, right)                                             \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mYou can find out more via the 'skills', 'traits', and 'research' commands. \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysCorrectInformationWithWeaponShieldAndArmorEquipped()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    command("equip blah", Player);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "weasels");
    shield.set("short", "Shield of Weasels");
    shield.set("defense class", 1);
    shield.set("material", "steel");
    shield.set("weapon type", "shield");
    move_object(shield, Player);
    command("equip weasels", Player);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", 0x00000200);
    move_object(armor, Player);
    command("equip stuff", Player);

    ExpectTrue(Player.executeCommand("?"));
    ExpectEq("\x1b[0;32mRob the title-less\n"
        "\x1b[0m\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mRace: \x1b[0m\x1b[0;32mHigh elf (Hillgarathi elf)       \x1b[0m\x1b[0;36mOverall Level: \x1b[0m\x1b[0;32m3                    \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36m  Hit Points: \x1b[0m\x1b[0;35;1m==\x1b[0m\x1b[0;31m........ \x1b[0m\x1b[0;36mSpell Points: \x1b[0m\x1b[0;35;1m==========\x1b[0m\x1b[0;31m \x1b[0m\x1b[0;36m     Stamina: \x1b[0m\x1b[0;35;1m==========\x1b[0m\x1b[0;31m \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;33m              30/125  \x1b[0m\x1b[0;33m                 152/152  \x1b[0m\x1b[0;33m                96/96      \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36m    Strength: \x1b[0m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0;36mIntelligence: \x1b[0m\x1b[0;33;1m14    \x1b[0m\x1b[0;34;1m(+4) \x1b[0m\x1b[0;36m      Wisdom: \x1b[0m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36m   Dexterity: \x1b[0m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m\x1b[0;36mConstitution: \x1b[0m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0;36m    Charisma: \x1b[0m\x1b[0;33;1m12    \x1b[0m\x1b[0;34;1m(+2) \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mGuild: \x1b[0m\x1b[0;33mFake fighter (Neophyte)     \x1b[0m\x1b[0;36mLevel: \x1b[0m\x1b[0;33m1          \x1b[0m\x1b[0;36mExperience: \x1b[0m\x1b[0;35;1m======\x1b[0m\x1b[0;31m....\x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mGuild: \x1b[0m\x1b[0;33mFake mage                   \x1b[0m\x1b[0;36mLevel: \x1b[0m\x1b[0;33m2          \x1b[0m\x1b[0;36mExperience: \x1b[0m\x1b[0;33;1m Level up \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mPrimary Weapon: \x1b[0m\x1b[0;33mSword of Bla...\x1b[0m\x1b[0;36m Attack: \x1b[0m\x1b[0;33m-65 to 35  \x1b[0m\x1b[0;36m      Damage: \x1b[0m\x1b[0;33m  9 to 12 \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mOffhand Weapon: \x1b[0m\x1b[0;33mShield of We...\x1b[0m\x1b[0;36m Attack: \x1b[0m\x1b[0;33m-81 to 19  \x1b[0m\x1b[0;36m      Damage: \x1b[0m\x1b[0;33m  0 to 1  \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36m Defend Attack: \x1b[0m\x1b[0;33m-96 to -64 \x1b[0m\x1b[0;36m       Soak: \x1b[0m\x1b[0;33m  3 to 5   \x1b[0m\x1b[0;36mEncumberance: \x1b[0m\x1b[0;33m 48       \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36m         Wimpy: \x1b[0m\x1b[0;33m  0%\x1b[0m\x1b[0;36m         Hunted by: \x1b[0m\x1b[0;33mNothing at all, aren't you lucky?  \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mYou are normal.  (Yeah, right)                                             \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mYou can find out more via the 'skills', 'traits', and 'research' commands. \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player.executeCommand("score"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Hit Points:.*[^=]==[^=]")), "shows two bars");
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "30/121")), "shows 30/121");

    Player.hitPoints(32);
    ExpectTrue(Player.executeCommand("score"));

    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Hit Points:.*[^=]=====[^=]")), "shows 5 bars");
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }), "62/121")), "shows 62/121");
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player.executeCommand("score"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Spell Points:.*[^=]==========[^=]")));
    Player.spellPoints(-30);
    ExpectTrue(Player.executeCommand("score"));

    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Spell Points:.*[^=]======[^=]")));
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player.executeCommand("score"));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Stamina:.*[^=]==========[^=]")));
    Player.staminaPoints(-30);
    ExpectTrue(Player.executeCommand("score"));

    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Stamina:.*[^=]======[^=]")));
}

/////////////////////////////////////////////////////////////////////////////
void SliderForExperienceDisplaysCorrectly()
{
    Player.addExperience(-2000);
    ExpectTrue(Player.executeCommand("score"));

    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Experience:.*[^=]===[^=]")));
    ExpectFalse(sizeof(regexp(({ Player.caughtMessage() }),
        "Experience:.*Level up")));

    Player.addExperience(2000);
    ExpectTrue(Player.executeCommand("score"));

    ExpectFalse(sizeof(regexp(({ Player.caughtMessage() }),
        "Experience:.*[^=]===[^=]")));
    ExpectTrue(sizeof(regexp(({ Player.caughtMessage() }),
        "Experience:.*Level up")));
}

/////////////////////////////////////////////////////////////////////////////
void VFlagDisplaysCombatStatistics()
{
    ExpectTrue(Player.executeCommand("? -v"));
    ExpectSubStringMatch("Best Kill.*Nemesis", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void VFlagWithRealKillsDisplaysCombatStatistics()
{
    object foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Nukulevee");
    foe.Race("undead horse");
    foe.effectiveLevel(20);

    Player.generateCombatStatistics(foe);
    Player.generateCombatStatistics(foe);
    destruct(foe);

    foe = clone_object("/lib/realizations/monster.c");
    foe.Name("Earl the Boorish");
    foe.Race("orc");
    foe.effectiveLevel(25);
    Player.generateCombatStatistics(foe);
    destruct(foe);

    ExpectTrue(Player.executeCommand("score -v"));
    ExpectSubStringMatch("Best Kill.*Earl.*Nemesis.*Nukulevee", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysUnicodeCharset()
{
    Player.charsetConfiguration("unicode");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    command("equip blah", Player);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "weasels");
    shield.set("short", "Shield of Weasels");
    shield.set("defense class", 1);
    shield.set("material", "steel");
    shield.set("weapon type", "shield");
    move_object(shield, Player);
    command("equip weasels", Player);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", 0x00000200);
    move_object(armor, Player);
    command("equip stuff", Player);

    ExpectTrue(Player.executeCommand("?"));
    ExpectEq("\x1b[0;32mRob the title-less\n"
        "\x1b[0m\x1b[0;31m\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 General \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557\n"
        "\x1b[0m\x1b[0;31m\u2551\x1b[0m \x1b[0;36mRace: \x1b[0m\x1b[0;32mHigh elf (Hillgarathi elf)       \x1b[0m\x1b[0;36mOverall Level: \x1b[0m\x1b[0;32m3                    \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Vitals \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n"
        "\x1b[0m\x1b[0;31m\u2551\x1b[0m \x1b[0;36m  Hit Points: \x1b[0m\x1b[0;35;1m\u25ac\u25ac\x1b[0m\x1b[0;31m\u2237\u2237\u2237\u2237\u2237\u2237\u2237\u2237 \x1b[0m\x1b[0;36mSpell Points: \x1b[0m\x1b[0;35;1m\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\x1b[0m\x1b[0;31m \x1b[0m\x1b[0;36m     Stamina: \x1b[0m\x1b[0;35;1m\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\x1b[0m\x1b[0;31m \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2551\x1b[0m \x1b[0;33m              30/125  \x1b[0m\x1b[0;33m                 152/152  \x1b[0m\x1b[0;33m                96/96      \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Attributes \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n"
        "\x1b[0m\x1b[0;31m\u2551\x1b[0m \x1b[0;36m    Strength: \x1b[0m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0;36mIntelligence: \x1b[0m\x1b[0;33;1m14    \x1b[0m\x1b[0;34;1m(+4) \x1b[0m\x1b[0;36m      Wisdom: \x1b[0m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2551\x1b[0m \x1b[0;36m   Dexterity: \x1b[0m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m\x1b[0;36mConstitution: \x1b[0m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0;36m    Charisma: \x1b[0m\x1b[0;33;1m12    \x1b[0m\x1b[0;34;1m(+2) \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Guilds \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n"
        "\x1b[0m\x1b[0;31m\u2551\x1b[0m \x1b[0;36mGuild: \x1b[0m\x1b[0;33mFake fighter (Neophyte)     \x1b[0m\x1b[0;36mLevel: \x1b[0m\x1b[0;33m1          \x1b[0m\x1b[0;36mExperience: \x1b[0m\x1b[0;35;1m\u25ac\u25ac\u25ac\u25ac\u25ac\u25ac\x1b[0m\x1b[0;31m\u2237\u2237\u2237\u2237\x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2551\x1b[0m \x1b[0;36mGuild: \x1b[0m\x1b[0;33mFake mage                   \x1b[0m\x1b[0;36mLevel: \x1b[0m\x1b[0;33m2          \x1b[0m\x1b[0;36mExperience: \x1b[0m\x1b[0;33;1m Level up \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Combat Information \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n" +
        "\x1b[0m\x1b[0;31m\u2551\x1b[0m \x1b[0;36mPrimary Weapon: \x1b[0m\x1b[0;33mSword of Bla...\x1b[0m\x1b[0;36m Attack: \x1b[0m\x1b[0;33m-65 to 35  \x1b[0m\x1b[0;36m      Damage: \x1b[0m\x1b[0;33m  9 to 12 \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2551\x1b[0m \x1b[0;36mOffhand Weapon: \x1b[0m\x1b[0;33mShield of We...\x1b[0m\x1b[0;36m Attack: \x1b[0m\x1b[0;33m-81 to 19  \x1b[0m\x1b[0;36m      Damage: \x1b[0m\x1b[0;33m  0 to 1  \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2551\x1b[0m \x1b[0;36m Defend Attack: \x1b[0m\x1b[0;33m-96 to -64 \x1b[0m\x1b[0;36m       Soak: \x1b[0m\x1b[0;33m  3 to 5   \x1b[0m\x1b[0;36mEncumberance: \x1b[0m\x1b[0;33m 48       \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2551\x1b[0m \x1b[0;36m         Wimpy: \x1b[0m\x1b[0;33m  0%\x1b[0m\x1b[0;36m         Hunted by: \x1b[0m\x1b[0;33mNothing at all, aren't you lucky?  \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 Details \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563\n"
        "\x1b[0m\x1b[0;31m\u2551\x1b[0m \x1b[0;36mYou are normal.  (Yeah, right)                                             \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u2551\x1b[0m \x1b[0;36mYou can find out more via the 'skills', 'traits', and 'research' commands. \x1b[0m \x1b[0;31m\u2551\x1b[0m\n"
        "\x1b[0;31m\u255a\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2561 \u2550 \u255e\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d\n"
        "\x1b[0m", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysNoColorCorrectly()
{
    Player.colorConfiguration("none");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    command("equip blah", Player);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "weasels");
    shield.set("short", "Shield of Weasels");
    shield.set("defense class", 1);
    shield.set("material", "steel");
    shield.set("weapon type", "shield");
    move_object(shield, Player);
    command("equip weasels", Player);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", 0x00000200);
    move_object(armor, Player);
    command("equip stuff", Player);

    ExpectTrue(Player.executeCommand("?"));
    ExpectEq("Rob the title-less\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Race: High elf (Hillgarathi elf)       Overall Level: 3                     |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "|   Hit Points: ==........ Spell Points: ==========      Stamina: ==========  |\n"
        "|               30/125                   152/152                  96/96       |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "|     Strength: 11    (+1) Intelligence: 14    (+4)       Wisdom: 10          |\n"
        "|    Dexterity: 10         Constitution: 11    (+1)     Charisma: 12    (+2)  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Guild: Fake fighter (Neophyte)     Level: 1          Experience: ======.... |\n"
        "| Guild: Fake mage                   Level: 2          Experience:  Level up  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| Primary Weapon: Sword of Bla... Attack: -65 to 35        Damage:   9 to 12  |\n"
        "| Offhand Weapon: Shield of We... Attack: -81 to 19        Damage:   0 to 1   |\n"
        "|  Defend Attack: -96 to -64        Soak:   3 to 5   Encumberance:  48        |\n"
        "|          Wimpy:   0%         Hunted by: Nothing at all, aren't you lucky?   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "| You are normal.  (Yeah, right)                                              |\n"
        "| You can find out more via the 'skills', 'traits', and 'research' commands.  |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysEightBitColorCorrectly()
{
    Player.colorConfiguration("8-bit");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    command("equip blah", Player);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "weasels");
    shield.set("short", "Shield of Weasels");
    shield.set("defense class", 1);
    shield.set("material", "steel");
    shield.set("weapon type", "shield");
    move_object(shield, Player);
    command("equip weasels", Player);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", 0x00000200);
    move_object(armor, Player);
    command("equip stuff", Player);

    ExpectTrue(Player.executeCommand("?"));
    ExpectEq("\x1b[0;38;5;144mRob the title-less\n"
        "\x1b[0m\x1b[0;38;5;124m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80mRace: \x1b[0m\x1b[0;38;5;2mHigh elf (Hillgarathi elf)       \x1b[0m\x1b[0;38;5;80mOverall Level: \x1b[0m\x1b[0;38;5;2m3                    \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80m  Hit Points: \x1b[0m\x1b[0;38;5;238;1m==\x1b[0m\x1b[0;38;5;9m........ \x1b[0m\x1b[0;38;5;80mSpell Points: \x1b[0m\x1b[0;38;5;238;1m==========\x1b[0m\x1b[0;38;5;9m \x1b[0m\x1b[0;38;5;80m     Stamina: \x1b[0m\x1b[0;38;5;238;1m==========\x1b[0m\x1b[0;38;5;9m \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;190m              30/125  \x1b[0m\x1b[0;38;5;190m                 152/152  \x1b[0m\x1b[0;38;5;190m                96/96      \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80m    Strength: \x1b[0m\x1b[0;38;5;190;1m11    \x1b[0m\x1b[0;38;5;20;1m(+1) \x1b[0m\x1b[0;38;5;80mIntelligence: \x1b[0m\x1b[0;38;5;190;1m14    \x1b[0m\x1b[0;38;5;20;1m(+4) \x1b[0m\x1b[0;38;5;80m      Wisdom: \x1b[0m\x1b[0;38;5;2m10    \x1b[0m\x1b[0;38;5;2m     \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80m   Dexterity: \x1b[0m\x1b[0;38;5;2m10    \x1b[0m\x1b[0;38;5;2m     \x1b[0m\x1b[0;38;5;80mConstitution: \x1b[0m\x1b[0;38;5;190;1m11    \x1b[0m\x1b[0;38;5;20;1m(+1) \x1b[0m\x1b[0;38;5;80m    Charisma: \x1b[0m\x1b[0;38;5;190;1m12    \x1b[0m\x1b[0;38;5;20;1m(+2) \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80mGuild: \x1b[0m\x1b[0;38;5;190mFake fighter (Neophyte)     \x1b[0m\x1b[0;38;5;80mLevel: \x1b[0m\x1b[0;38;5;190m1          \x1b[0m\x1b[0;38;5;80mExperience: \x1b[0m\x1b[0;38;5;238;1m======\x1b[0m\x1b[0;38;5;9m....\x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80mGuild: \x1b[0m\x1b[0;38;5;190mFake mage                   \x1b[0m\x1b[0;38;5;80mLevel: \x1b[0m\x1b[0;38;5;190m2          \x1b[0m\x1b[0;38;5;80mExperience: \x1b[0m\x1b[0;38;5;190;1m Level up \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80mPrimary Weapon: \x1b[0m\x1b[0;38;5;190mSword of Bla...\x1b[0m\x1b[0;38;5;80m Attack: \x1b[0m\x1b[0;38;5;190m-65 to 35  \x1b[0m\x1b[0;38;5;80m      Damage: \x1b[0m\x1b[0;38;5;190m  9 to 12 \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80mOffhand Weapon: \x1b[0m\x1b[0;38;5;190mShield of We...\x1b[0m\x1b[0;38;5;80m Attack: \x1b[0m\x1b[0;38;5;190m-81 to 19  \x1b[0m\x1b[0;38;5;80m      Damage: \x1b[0m\x1b[0;38;5;190m  0 to 1  \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80m Defend Attack: \x1b[0m\x1b[0;38;5;190m-96 to -64 \x1b[0m\x1b[0;38;5;80m       Soak: \x1b[0m\x1b[0;38;5;190m  3 to 5   \x1b[0m\x1b[0;38;5;80mEncumberance: \x1b[0m\x1b[0;38;5;190m 48       \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80m         Wimpy: \x1b[0m\x1b[0;38;5;190m  0%\x1b[0m\x1b[0;38;5;80m         Hunted by: \x1b[0m\x1b[0;38;5;190mNothing at all, aren't you lucky?  \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80mYou are normal.  (Yeah, right)                                             \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m|\x1b[0m \x1b[0;38;5;80mYou can find out more via the 'skills', 'traits', and 'research' commands. \x1b[0m \x1b[0;38;5;124m|\x1b[0m\n"
        "\x1b[0;38;5;124m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysTwentyFourBitColorCorrectly()
{
    Player.colorConfiguration("24-bit");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    command("equip blah", Player);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "weasels");
    shield.set("short", "Shield of Weasels");
    shield.set("defense class", 1);
    shield.set("material", "steel");
    shield.set("weapon type", "shield");
    move_object(shield, Player);
    command("equip weasels", Player);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", 0x00000200);
    move_object(armor, Player);
    command("equip stuff", Player);

    ExpectTrue(Player.executeCommand("?"));
    ExpectEq("\x1b[0;38;2;100;180;150mRob the title-less\n"
        "\x1b[0m\x1b[0;38;2;160;10;0m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190mRace: \x1b[0m\x1b[0;38;2;170;180;110mHigh elf (Hillgarathi elf)       \x1b[0m\x1b[0;38;2;180;180;190mOverall Level: \x1b[0m\x1b[0;38;2;170;180;110m3                    \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190m  Hit Points: \x1b[0m\x1b[0;38;2;60;60;70;1m==\x1b[0m\x1b[0;38;2;200;0;0m........ \x1b[0m\x1b[0;38;2;180;180;190mSpell Points: \x1b[0m\x1b[0;38;2;60;60;70;1m==========\x1b[0m\x1b[0;38;2;200;0;0m \x1b[0m\x1b[0;38;2;180;180;190m     Stamina: \x1b[0m\x1b[0;38;2;60;60;70;1m==========\x1b[0m\x1b[0;38;2;200;0;0m \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;200;200;0m              30/125  \x1b[0m\x1b[0;38;2;200;200;0m                 152/152  \x1b[0m\x1b[0;38;2;200;200;0m                96/96      \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190m    Strength: \x1b[0m\x1b[0;38;2;200;200;0;1m11    \x1b[0m\x1b[0;38;2;0;0;220;1m(+1) \x1b[0m\x1b[0;38;2;180;180;190mIntelligence: \x1b[0m\x1b[0;38;2;200;200;0;1m14    \x1b[0m\x1b[0;38;2;0;0;220;1m(+4) \x1b[0m\x1b[0;38;2;180;180;190m      Wisdom: \x1b[0m\x1b[0;38;2;170;180;110m10    \x1b[0m\x1b[0;38;2;170;180;110m     \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190m   Dexterity: \x1b[0m\x1b[0;38;2;170;180;110m10    \x1b[0m\x1b[0;38;2;170;180;110m     \x1b[0m\x1b[0;38;2;180;180;190mConstitution: \x1b[0m\x1b[0;38;2;200;200;0;1m11    \x1b[0m\x1b[0;38;2;0;0;220;1m(+1) \x1b[0m\x1b[0;38;2;180;180;190m    Charisma: \x1b[0m\x1b[0;38;2;200;200;0;1m12    \x1b[0m\x1b[0;38;2;0;0;220;1m(+2) \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190mGuild: \x1b[0m\x1b[0;38;2;200;200;0mFake fighter (Neophyte)     \x1b[0m\x1b[0;38;2;180;180;190mLevel: \x1b[0m\x1b[0;38;2;200;200;0m1          \x1b[0m\x1b[0;38;2;180;180;190mExperience: \x1b[0m\x1b[0;38;2;60;60;70;1m======\x1b[0m\x1b[0;38;2;200;0;0m....\x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190mGuild: \x1b[0m\x1b[0;38;2;200;200;0mFake mage                   \x1b[0m\x1b[0;38;2;180;180;190mLevel: \x1b[0m\x1b[0;38;2;200;200;0m2          \x1b[0m\x1b[0;38;2;180;180;190mExperience: \x1b[0m\x1b[0;38;2;200;200;0;1m Level up \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190mPrimary Weapon: \x1b[0m\x1b[0;38;2;200;200;0mSword of Bla...\x1b[0m\x1b[0;38;2;180;180;190m Attack: \x1b[0m\x1b[0;38;2;200;200;0m-65 to 35  \x1b[0m\x1b[0;38;2;180;180;190m      Damage: \x1b[0m\x1b[0;38;2;200;200;0m  9 to 12 \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190mOffhand Weapon: \x1b[0m\x1b[0;38;2;200;200;0mShield of We...\x1b[0m\x1b[0;38;2;180;180;190m Attack: \x1b[0m\x1b[0;38;2;200;200;0m-81 to 19  \x1b[0m\x1b[0;38;2;180;180;190m      Damage: \x1b[0m\x1b[0;38;2;200;200;0m  0 to 1  \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190m Defend Attack: \x1b[0m\x1b[0;38;2;200;200;0m-96 to -64 \x1b[0m\x1b[0;38;2;180;180;190m       Soak: \x1b[0m\x1b[0;38;2;200;200;0m  3 to 5   \x1b[0m\x1b[0;38;2;180;180;190mEncumberance: \x1b[0m\x1b[0;38;2;200;200;0m 48       \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190m         Wimpy: \x1b[0m\x1b[0;38;2;200;200;0m  0%\x1b[0m\x1b[0;38;2;180;180;190m         Hunted by: \x1b[0m\x1b[0;38;2;200;200;0mNothing at all, aren't you lucky?  \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190mYou are normal.  (Yeah, right)                                             \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m|\x1b[0m \x1b[0;38;2;180;180;190mYou can find out more via the 'skills', 'traits', and 'research' commands. \x1b[0m \x1b[0;38;2;160;10;0m|\x1b[0m\n"
        "\x1b[0;38;2;160;10;0m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysScreenReaderCorrectly()
{
    Player.colorConfiguration("none");
    Player.charsetConfiguration("screen reader");

    object weapon = clone_object("/lib/items/weapon");
    weapon.set("name", "blah");
    weapon.set("weapon type", "long sword");
    weapon.set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    command("equip blah", Player);

    object shield = clone_object("/lib/items/weapon");
    shield.set("name", "weasels");
    shield.set("short", "Shield of Weasels");
    shield.set("defense class", 1);
    shield.set("material", "steel");
    shield.set("weapon type", "shield");
    move_object(shield, Player);
    command("equip weasels", Player);

    object armor = clone_object("/lib/items/armor");
    armor.set("name", "stuff");
    armor.set("bonus hit points", 4);
    armor.set("armor class", 5);
    armor.set("armor type", "chainmail");
    armor.set("equipment locations", 0x00000200);
    move_object(armor, Player);
    command("equip stuff", Player);

    ExpectTrue(Player.executeCommand("?"));
    ExpectEq("Rob the title-less\n"
        "                                     General                                    \n"
        "  Race: High elf (Hillgarathi elf)       Overall Level: 3                      \n"
        "                                     Vitals                                     \n"
        "    Hit Points:  24%       Spell Points: 100%            Stamina: 100%         \n"
        "                30/125                   152/152                  96/96        \n"
        "                                   Attributes                                   \n"
        "      Strength: 11    (+1) Intelligence: 14    (+4)       Wisdom: 10           \n"
        "     Dexterity: 10         Constitution: 11    (+1)     Charisma: 12    (+2)   \n"
        "                                     Guilds                                     \n"
        "  Guild: Fake fighter (Neophyte)     Level: 1          Experience:     66%     \n"
        "  Guild: Fake mage                   Level: 2          Experience:  Level up   \n"
        "                               Combat Information                               \n"
        "  Primary Weapon: Sword of Bla... Attack: -65 to 35        Damage:   9 to 12   \n"
        "  Offhand Weapon: Shield of We... Attack: -81 to 19        Damage:   0 to 1    \n"
        "   Defend Attack: -96 to -64        Soak:   3 to 5   Encumberance:  48         \n"
        "           Wimpy:   0%         Hunted by: Nothing at all, aren't you lucky?    \n"
        "                                     Details                                    \n"
        "  You are normal.  (Yeah, right)                                               \n"
        "  You can find out more via the 'skills', 'traits', and 'research' commands.   \n"
        "                                                                                \n"
        "", Player.caughtMessage());
}
