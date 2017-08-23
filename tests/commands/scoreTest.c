//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Player->spellPoints(Player->maxSpellPoints());
    Player->staminaPoints(Player->maxStaminaPoints());

    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    object guild = load_object("/lib/tests/support/guilds/mageGuild.c");
    guild->init();
    Player->joinGuild("mage");
    Player->addExperience(1700);
    Player->advanceLevel("mage");

    guild = load_object("/lib/tests/support/guilds/testGuild.c");
    guild->init();
    Player->joinGuild("test");
    Player->addExperience(2000);
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
    ExpectEq("[0;32mRob the title-less[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m [0;36mRace:[0m [0;32mHigh elf (Hillgarathi elf)      [0m [0;36mOverall Level:[0m [0;32m3                     [0m[0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m[0;36m  Hit Points:[0m [0;35;1m==[0m[0;31m........[0m  [0;36mSpell Points:[0m [0;35;1m==========[0m[0;31m[0m  [0;36m     Stamina:[0m [0;35;1m==========[0m[0;31m[0m [0;31m|[0m\n"
        "[0;31m|[0m              [0;33m30/106     [0m               [0;33m146/146    [0m               [0;33m96/96      [0m[0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m[0;36m    Strength:[0m [0;32m[0;33;1m11    [0m[0;34;1m(+1) [0m[0m [0;36mIntelligence:[0m [0;32m[0;33;1m12    [0m[0;34;1m(+2) [0m[0m [0;36m      Wisdom:[0m [0;32m[0;32m10    [0m[0;32m     [0m[0m[0;31m|[0m\n"
        "[0;31m|[0m[0;36m   Dexterity:[0m [0;32m[0;32m10    [0m[0;32m     [0m[0m [0;36mConstitution:[0m [0;32m[0;33;1m11    [0m[0;34;1m(+1) [0m[0m [0;36m    Charisma:[0m [0;32m[0;33;1m12    [0m[0;34;1m(+2) [0m[0m[0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m [0;36mGuild:[0m [0;33mTest (Neophyte)            [0m [0;36mLevel:[0m [0;33m1         [0m [0;36mExperience:[0m [0;33m[0;34;1m======[0m[0;31m....[0m[0m [0;31m|[0m\n"
        "[0;31m|[0m [0;36mGuild:[0m [0;33mMage                       [0m [0;36mLevel:[0m [0;33m2         [0m [0;36mExperience:[0m [0;33m[0;34;1m[0m[0;33;1m Level up [0m[0m [0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m [0;36mPrimary Weapon:[0m [0;33mSword of Bla...[0m [0;36mAttack: [0m[0;33m-21 to 79[0m        [0;36mDamage: [0m[0;33m9 to 12[0m    [0;31m|[0m\n"
        "[0;31m|[0m  [0;36mDefend Attack: [0m[0;33m0 to 0[0m            [0;36mSoak: [0m[0;33m0 to 0[0m     [0;36mEncumberance: [0m[0;33m3[0m          [0;31m|[0m\n"
        "[0;31m|[0m [0;36m         Wimpy: [0m[0;33m0% [0m[0;36m          Hunted by: [0m[0;33mNothing at all, aren't you lucky?  [0m [0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m [0;36mYou are normal.  (Yeah, right)                                             [0m [0;31m|[0m\n"
        "[0;31m|[0m [0;36mYou can find out more via the 'skills', 'traits', and 'research' commands. [0m [0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m", Player->caughtMessage());
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
    ExpectEq("[0;32mRob the title-less[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ General +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m [0;36mRace:[0m [0;32mHigh elf (Hillgarathi elf)      [0m [0;36mOverall Level:[0m [0;32m3                     [0m[0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Vitals +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m[0;36m  Hit Points:[0m [0;35;1m==[0m[0;31m........[0m  [0;36mSpell Points:[0m [0;35;1m==========[0m[0;31m[0m  [0;36m     Stamina:[0m [0;35;1m==========[0m[0;31m[0m [0;31m|[0m\n"
        "[0;31m|[0m              [0;33m30/110     [0m               [0;33m146/146    [0m               [0;33m96/96      [0m[0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Attributes +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m[0;36m    Strength:[0m [0;32m[0;33;1m11    [0m[0;34;1m(+1) [0m[0m [0;36mIntelligence:[0m [0;32m[0;33;1m12    [0m[0;34;1m(+2) [0m[0m [0;36m      Wisdom:[0m [0;32m[0;32m10    [0m[0;32m     [0m[0m[0;31m|[0m\n"
        "[0;31m|[0m[0;36m   Dexterity:[0m [0;32m[0;32m10    [0m[0;32m     [0m[0m [0;36mConstitution:[0m [0;32m[0;33;1m11    [0m[0;34;1m(+1) [0m[0m [0;36m    Charisma:[0m [0;32m[0;33;1m12    [0m[0;34;1m(+2) [0m[0m[0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Guilds +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m [0;36mGuild:[0m [0;33mTest (Neophyte)            [0m [0;36mLevel:[0m [0;33m1         [0m [0;36mExperience:[0m [0;33m[0;34;1m======[0m[0;31m....[0m[0m [0;31m|[0m\n"
        "[0;31m|[0m [0;36mGuild:[0m [0;33mMage                       [0m [0;36mLevel:[0m [0;33m2         [0m [0;36mExperience:[0m [0;33m[0;34;1m[0m[0;33;1m Level up [0m[0m [0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Combat Information +-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m [0;36mPrimary Weapon:[0m [0;33mSword of Bla...[0m [0;36mAttack: [0m[0;33m-66 to 34[0m        [0;36mDamage: [0m[0;33m9 to 12[0m    [0;31m|[0m\n"
        "[0;31m|[0m [0;36mOffhand Weapon:[0m [0;33mShield of We...[0m [0;36mAttack: [0m[0;33m-82 to 18[0m        [0;36mDamage: [0m[0;33m0 to 1[0m     [0;31m|[0m\n"
        "[0;31m|[0m  [0;36mDefend Attack: [0m[0;33m-96 to -64[0m        [0;36mSoak: [0m[0;33m3 to 5[0m     [0;36mEncumberance: [0m[0;33m48[0m         [0;31m|[0m\n"
        "[0;31m|[0m [0;36m         Wimpy: [0m[0;33m0% [0m[0;36m          Hunted by: [0m[0;33mNothing at all, aren't you lucky?  [0m [0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+ Details +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m[0;31m|[0m [0;36mYou are normal.  (Yeah, right)                                             [0m [0;31m|[0m\n"
        "[0;31m|[0m [0;36mYou can find out more via the 'skills', 'traits', and 'research' commands. [0m [0;31m|[0m\n"
        "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "[0m", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HitPointsSliderBarsDisplayCorrectly()
{
    ExpectTrue(Player->executeCommand("score"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Hit Points:.*[^=]==[^=]")));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "30/106")));

    Player->hitPoints(30);
    ExpectTrue(Player->executeCommand("score"));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }),
        "Hit Points:.*[^=]=====[^=]")));
    ExpectTrue(sizeof(regexp(({ Player->caughtMessage() }), "60/106")));
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
        "Spell Points:.*[^=]=======[^=]")));
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