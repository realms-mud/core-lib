//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("rob");
    Player->hitPoints(30);
    Player->spellPoints(30);
    Player->staminaPoints(30);
    Player->Str(10);
    Player->Int(10);
    Player->Dex(10);
    Player->Wis(10);
    Player->Con(10);
    Player->Chr(10);
    Player->addCommands();
    Player->Race("high elf");
    Player->addTrait("/lib/modules/traits/racial/hillgarathElf.c");
    Player->addTrait("/lib/modules/traits/genetic/smart.c");
    Player->spellPoints(Player->maxSpellPoints());
    Player->staminaPoints(Player->maxStaminaPoints());

    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    object guild = load_object("/lib/tests/support/guilds/mageGuild.c");
    guild->init();
    Player->joinGuild("mage");
    Player->addExperience(1700);
    Player->advanceLevel("mage");

    guild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    guild->init();
    Player->joinGuild("fighter");
    Player->addExperience(2000);

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
    ExpectTrue(Player->executeCommand("score"));
}

/////////////////////////////////////////////////////////////////////////////
void CanExecuteScoreAsQuestionmark()
{
    ExpectTrue(Player->executeCommand("?"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpIsNotGreedy()
{
    ExpectFalse(Player->executeCommand("scoreblah"));
    ExpectFalse(Player->executeCommand("ascored"));
    ExpectFalse(Player->executeCommand("blah?"));
}

/////////////////////////////////////////////////////////////////////////////
void ExecuteRegexpFailsIfInvalidFlagsPassed()
{
    ExpectFalse(Player->executeCommand("score -t"));
    ExpectFalse(Player->executeCommand("score -com"));
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysCorrectInformationWithWeaponEquipped()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    weapon->equip("blah");

    ExpectTrue(Player->executeCommand("score"));
    ExpectEq("\x1b[0;32mRob the title-less\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mRace:\x1b[0m \x1b[0;32mHigh elf (Hillgarathi elf)      \x1b[0m \x1b[0;36mOverall Level:\x1b[0m \x1b[0;32m3                     \x1b[0m\x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m\x1b[0;36m  Hit Points:\x1b[0m \x1b[0;35;1m==\x1b[0m\x1b[0;31m........\x1b[0m  \x1b[0;36mSpell Points:\x1b[0m \x1b[0;35;1m==========\x1b[0m\x1b[0;31m\x1b[0m  \x1b[0;36m     Stamina:\x1b[0m \x1b[0;35;1m==========\x1b[0m\x1b[0;31m\x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m              \x1b[0;33m30/121     \x1b[0m               \x1b[0;33m152/152    \x1b[0m               \x1b[0;33m96/96      \x1b[0m\x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m\x1b[0;36m    Strength:\x1b[0m \x1b[0;32m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0m \x1b[0;36mIntelligence:\x1b[0m \x1b[0;32m\x1b[0;33;1m14    \x1b[0m\x1b[0;34;1m(+4) \x1b[0m\x1b[0m \x1b[0;36m      Wisdom:\x1b[0m \x1b[0;32m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m\x1b[0m\x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m\x1b[0;36m   Dexterity:\x1b[0m \x1b[0;32m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m\x1b[0m \x1b[0;36mConstitution:\x1b[0m \x1b[0;32m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0m \x1b[0;36m    Charisma:\x1b[0m \x1b[0;32m\x1b[0;33;1m12    \x1b[0m\x1b[0;34;1m(+2) \x1b[0m\x1b[0m\x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mGuild:\x1b[0m \x1b[0;33mFighter (Neophyte)         \x1b[0m \x1b[0;36mLevel:\x1b[0m \x1b[0;33m1         \x1b[0m \x1b[0;36mExperience:\x1b[0m \x1b[0;33m\x1b[0;34;1m======\x1b[0m\x1b[0;31m....\x1b[0m\x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mGuild:\x1b[0m \x1b[0;33mMage                       \x1b[0m \x1b[0;36mLevel:\x1b[0m \x1b[0;33m2         \x1b[0m \x1b[0;36mExperience:\x1b[0m \x1b[0;33m\x1b[0;34;1m\x1b[0m\x1b[0;33;1m Level up \x1b[0m\x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mPrimary Weapon:\x1b[0m \x1b[0;33mSword of Bla...\x1b[0m \x1b[0;36mAttack: \x1b[0m\x1b[0;33m-20 to 80\x1b[0m        \x1b[0;36mDamage: \x1b[0m\x1b[0;33m9 to 12\x1b[0m    \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m  \x1b[0;36mDefend Attack: \x1b[0m\x1b[0;33m0 to 0\x1b[0m            \x1b[0;36mSoak: \x1b[0m\x1b[0;33m0 to 0\x1b[0m     \x1b[0;36mEncumberance: \x1b[0m\x1b[0;33m3\x1b[0m          \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36m         Wimpy: \x1b[0m\x1b[0;33m0% \x1b[0m\x1b[0;36m          Hunted by: \x1b[0m\x1b[0;33mNothing at all, aren't you lucky?  \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mYou are normal.  (Yeah, right)                                             \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mYou can find out more via the 'skills', 'traits', and 'research' commands. \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ScoreDisplaysCorrectInformationWithWeaponShieldAndArmorEquipped()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah Really Long Name");
    move_object(weapon, Player);
    weapon->equip("blah");

    object shield = clone_object("/lib/items/weapon");
    shield->set("name", "weasels");
    shield->set("short", "Shield of Weasels");
    shield->set("defense class", 1);
    shield->set("material", "steel");
    shield->set("weapon type", "shield");
    move_object(shield, Player);
    shield->equip("weasels");

    object armor = clone_object("/lib/items/armor");
    armor->set("name", "stuff");
    armor->set("bonus hit points", 4);
    armor->set("armor class", 5);
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", 0x00000200);
    move_object(armor, Player);
    armor->equip("stuff");

    ExpectTrue(Player->executeCommand("?"));
    ExpectEq("\x1b[0;32mRob the title-less\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mRace:\x1b[0m \x1b[0;32mHigh elf (Hillgarathi elf)      \x1b[0m \x1b[0;36mOverall Level:\x1b[0m \x1b[0;32m3                     \x1b[0m\x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m\x1b[0;36m  Hit Points:\x1b[0m \x1b[0;35;1m==\x1b[0m\x1b[0;31m........\x1b[0m  \x1b[0;36mSpell Points:\x1b[0m \x1b[0;35;1m==========\x1b[0m\x1b[0;31m\x1b[0m  \x1b[0;36m     Stamina:\x1b[0m \x1b[0;35;1m==========\x1b[0m\x1b[0;31m\x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m              \x1b[0;33m30/125     \x1b[0m               \x1b[0;33m152/152    \x1b[0m               \x1b[0;33m96/96      \x1b[0m\x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m\x1b[0;36m    Strength:\x1b[0m \x1b[0;32m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0m \x1b[0;36mIntelligence:\x1b[0m \x1b[0;32m\x1b[0;33;1m14    \x1b[0m\x1b[0;34;1m(+4) \x1b[0m\x1b[0m \x1b[0;36m      Wisdom:\x1b[0m \x1b[0;32m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m\x1b[0m\x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m\x1b[0;36m   Dexterity:\x1b[0m \x1b[0;32m\x1b[0;32m10    \x1b[0m\x1b[0;32m     \x1b[0m\x1b[0m \x1b[0;36mConstitution:\x1b[0m \x1b[0;32m\x1b[0;33;1m11    \x1b[0m\x1b[0;34;1m(+1) \x1b[0m\x1b[0m \x1b[0;36m    Charisma:\x1b[0m \x1b[0;32m\x1b[0;33;1m12    \x1b[0m\x1b[0;34;1m(+2) \x1b[0m\x1b[0m\x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mGuild:\x1b[0m \x1b[0;33mFighter (Neophyte)         \x1b[0m \x1b[0;36mLevel:\x1b[0m \x1b[0;33m1         \x1b[0m \x1b[0;36mExperience:\x1b[0m \x1b[0;33m\x1b[0;34;1m======\x1b[0m\x1b[0;31m....\x1b[0m\x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mGuild:\x1b[0m \x1b[0;33mMage                       \x1b[0m \x1b[0;36mLevel:\x1b[0m \x1b[0;33m2         \x1b[0m \x1b[0;36mExperience:\x1b[0m \x1b[0;33m\x1b[0;34;1m\x1b[0m\x1b[0;33;1m Level up \x1b[0m\x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mPrimary Weapon:\x1b[0m \x1b[0;33mSword of Bla...\x1b[0m \x1b[0;36mAttack: \x1b[0m\x1b[0;33m-65 to 35\x1b[0m        \x1b[0;36mDamage: \x1b[0m\x1b[0;33m9 to 12\x1b[0m    \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mOffhand Weapon:\x1b[0m \x1b[0;33mShield of We...\x1b[0m \x1b[0;36mAttack: \x1b[0m\x1b[0;33m-81 to 19\x1b[0m        \x1b[0;36mDamage: \x1b[0m\x1b[0;33m0 to 1\x1b[0m     \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m  \x1b[0;36mDefend Attack: \x1b[0m\x1b[0;33m-96 to -64\x1b[0m        \x1b[0;36mSoak: \x1b[0m\x1b[0;33m3 to 5\x1b[0m     \x1b[0;36mEncumberance: \x1b[0m\x1b[0;33m48\x1b[0m         \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36m         Wimpy: \x1b[0m\x1b[0;33m0% \x1b[0m\x1b[0;36m          Hunted by: \x1b[0m\x1b[0;33mNothing at all, aren't you lucky?  \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m\x1b[0;31m|\x1b[0m \x1b[0;36mYou are normal.  (Yeah, right)                                             \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m|\x1b[0m \x1b[0;36mYou can find out more via the 'skills', 'traits', and 'research' commands. \x1b[0m \x1b[0;31m|\x1b[0m\n"
        "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "\x1b[0m", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player->executeCommand("score"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Hit Points:.*[^=]==[^=]")), "shows two bars");
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "30/121")), "shows 30/121");

    Player->hitPoints(32);
    ExpectTrue(Player->executeCommand("score"));

    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Hit Points:.*[^=]=====[^=]")), "shows 5 bars");
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "62/121")), "shows 62/121");
}

/////////////////////////////////////////////////////////////////////////////
void SpellPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player->executeCommand("score"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Spell Points:.*[^=]==========[^=]")));
    Player->spellPoints(-30);
    ExpectTrue(Player->executeCommand("score"));

    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Spell Points:.*[^=]======[^=]")));
}

/////////////////////////////////////////////////////////////////////////////
void StaminaPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player->executeCommand("score"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Stamina:.*[^=]==========[^=]")));
    Player->staminaPoints(-30);
    ExpectTrue(Player->executeCommand("score"));

    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Stamina:.*[^=]======[^=]")));
}

/////////////////////////////////////////////////////////////////////////////
void SliderForExperienceDisplaysCorrectly()
{
    Player->addExperience(-2000);
    ExpectTrue(Player->executeCommand("score"));

    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Experience:.*[^=]===[^=]")));
    ExpectFalse(sizeof(regexp(({ Player->caughtMessage() }),
        "Experience:.*Level up")));

    Player->addExperience(2000);
    ExpectTrue(Player->executeCommand("score"));

    ExpectFalse(sizeof(regexp(({ Player->caughtMessage() }),
        "Experience:.*[^=]===[^=]")));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Experience:.*Level up")));
}

/////////////////////////////////////////////////////////////////////////////
void VFlagDisplaysCombatStatistics()
{
    ExpectTrue(Player->executeCommand("? -v"));
    ExpectSubStringMatch("Best Kill.*Nemesis", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void VFlagWithRealKillsDisplaysCombatStatistics()
{
    object foe = clone_object("/lib/realizations/monster");
    foe->Name("Nukulevee");
    foe->Race("undead horse");
    foe->effectiveLevel(20);

    Player->generateCombatStatistics(foe);
    Player->generateCombatStatistics(foe);
    destruct(foe);

    foe = clone_object("/lib/realizations/monster");
    foe->Name("Earl the Boorish");
    foe->Race("orc");
    foe->effectiveLevel(25);
    Player->generateCombatStatistics(foe);
    destruct(foe);

    ExpectTrue(Player->executeCommand("score -v"));
    ExpectSubStringMatch("Best Kill.*Earl.*Nemesis.*Nukulevee", Player->caughtMessage());
}
