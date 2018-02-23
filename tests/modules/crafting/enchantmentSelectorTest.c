//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/crafting/selectMaterialsSelector.c");
    Selector->setItem("long sword");
    Selector->setType("weapons");
    Selector->setSubType("swords");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();

    Player->Wis(50);
    Player->Str(50);
    Player->Int(50);
    Player->addSkillPoints(500);
    Player->advanceSkill("blacksmithing", 20);
    Player->advanceSkill("metal crafting", 10);
    Player->advanceSkill("weapon smithing", 10);
    Player->advanceSkill("chemistry", 10);
    Player->advanceSkill("physics", 10);
    Player->advanceSkill("spellcraft", 20);
    Player->advanceSkill("elemental fire", 20);
    Player->addResearchPoints(20);

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/craftWeapons.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftBasicSwords.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftLongSwords.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/craftEnchantments.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c"));

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingEnchantDisplaysEnchantmentTypeMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);

    ExpectEq("[0;36mSelect Enchantment type - [0m[0;37;1mchoose the enchantment type with which to craft[0m:\n"
        "    [[0;31;1m1[0m] - [0;32mAbilities           [0m     \n"
        "    [[0;31;1m2[0m] - [0;32mAttributes          [0m     \n"
        "    [[0;31;1m3[0m] - [0;32mDefensive           [0m     \n"
        "    [[0;31;1m4[0m] - [0;32mOffensive           [0m     \n"
        "    [[0;31;1m5[0m] - [0;32mSkills              [0m     \n"
        "    [[0;31;1m6[0m] - [0;32mVitals              [0m     \n"
        "    [[0;31;1m7[0m] - [0;32mExit Select Enchantment type Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 7.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingEnchantAbilitiesDisplaysAbilitiesMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("1", Player);

    ExpectEq("[0;36mSelect Enchant abilities - [0m[0;37;1mchoose the enchant abilities with which to craft[0m:\n"
        "    [[0;31;1m1[0m] - [0;32mExit Select Enchant abilities Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 1. You may also undo or reset.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "[0;32mEach [0;35;1m*[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingEnchantAttributesDisplaysAttributesMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("2", Player);

    ExpectEq("[0;36mSelect Enchant attributes - [0m[0;37;1mchoose the enchant attributes with which to craft[0m:\n"
        "    [[0;31;1m1[0m] - [0;31mEnhance charisma    [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m2[0m] - [0;31mEnhance constitution[0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m3[0m] - [0;31mEnhance dexterity   [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m4[0m] - [0;31mEnhance intelligence[0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m] - [0;31mEnhance strength    [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m6[0m] - [0;31mEnhance wisdom      [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m] - [0;32mExit Select Enchant attributes Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 7. You may also undo or reset.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "[0;32mEach [0;35;1m*[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingDefensiveEnchantmentDisplaysDefensiveMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("3", Player);

    ExpectEq("[0;36mSelect Enchant defensive - [0m[0;37;1mchoose the enchant defensive with which to craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mAcid resistance     [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;31mAir resistance      [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m3[0m]  - [0;31mChaos resistance    [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m4[0m]  - [0;31mCold resistance     [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;31mDamage reflection   [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m6[0m]  - [0;31mDamage soak         [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m]  - [0;31mDisease resistance  [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m8[0m]  - [0;31mEarth resistance    [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m9[0m]  - [0;31mElectricity resis...[0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;31mEnergy resistance   [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m11[0m] - [0;31mEvil resistance     [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m12[0m] - [0;32mFire resistance     [0m     \n"
        "    [[0;31;1m13[0m] - [0;31mGood resistance     [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m14[0m] - [0;31mMagical resistance  [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m15[0m] - [0;31mNeutral resistance  [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m16[0m] - [0;31mParalysis resistance[0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m17[0m] - [0;31mPoison resistance   [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m18[0m] - [0;31mPsionic resistance  [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m19[0m] - [0;31mSonic resistance    [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;31mUndead resistance   [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m21[0m] - [0;31mWater resistance    [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m22[0m] - [0;31mWeapon defense      [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m23[0m] - [0;32mExit Select Enchant defensive Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 23. You may also undo or reset.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "[0;32mEach [0;35;1m*[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingOffensiveEnchantmentDisplaysOffensiveMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);

    ExpectEq("[0;36mSelect Enchant offensive - [0m[0;37;1mchoose the enchant offensive with which to craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mAcid enchantment    [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;31mAdditional attack   [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m3[0m]  - [0;31mAir enchantment     [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m4[0m]  - [0;31mChaos enchantment   [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;31mCold enchantment    [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m6[0m]  - [0;31mDisease enchantment [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m]  - [0;31mEarth enchantment   [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m8[0m]  - [0;31mElectricity encha...[0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m9[0m]  - [0;31mEnergy enchantment  [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;31mEvil enchantment    [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m11[0m] - [0;32mFire enchantment    [0m     "
        "    [[0;31;1m12[0m] - [0;31mGood enchantment    [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m13[0m] - [0;31mMagical enchantment [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m14[0m] - [0;31mNeutral enchantment [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m15[0m] - [0;31mParalysis enchant...[0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m16[0m] - [0;31mPoison enchantment  [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m17[0m] - [0;31mPsionic enchantment [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m18[0m] - [0;31mSonic enchantment   [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m19[0m] - [0;31mUndead enchantment  [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;31mWater enchantment   [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m21[0m] - [0;31mWeapon attack       [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m22[0m] - [0;31mWeapon damage       [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m23[0m] - [0;32mExit Select Enchant offensive Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 23. You may also undo or reset.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "[0;32mEach [0;35;1m*[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingSkillsEnchantmentDisplaysSkillsMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("5", Player);

    ExpectEq("[0;36mSelect Enchant skills - [0m[0;37;1mchoose the enchant skills with which to craft[0m:\n"
        "    [[0;31;1m1[0m] - [0;32mExit Select Enchant skills Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 1. You may also undo or reset.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "[0;32mEach [0;35;1m*[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingVitalsEnchantmentDisplaysVitalsMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("6", Player);

    ExpectEq("[0;36mSelect Enchant vitals - [0m[0;37;1mchoose the enchant vitals with which to craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mHeal hit points a...[0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;31mHeal hit points rate[0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m3[0m]  - [0;31mHeal spell points...[0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m4[0m]  - [0;31mHeal spell points...[0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;31mHeal stamina poin...[0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m6[0m]  - [0;31mHeal stamina poin...[0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m]  - [0;31mHit points          [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m8[0m]  - [0;31mSpell points        [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m9[0m]  - [0;31mStamina points      [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;32mExit Select Enchant vitals Menu[0m     \n"
        "[0;32;1mYou must select a number from 1 to 10. You may also undo or reset.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou can imbue this item with 1 more (out of 1) enchantments.\n"
        "[0;32mEach [0;35;1m*[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitReturnsToPreviousMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);
    command("7", Player);

    ExpectSubStringMatch("Exit Craft Long sword Menu",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNotAddMoreThanMaximumEnchantmentsAllowed()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m.*4 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*[)].*3 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*[)].*2 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*\\*[)].*1 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*\\*[)].*1 more", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionCanBeZeroToThreeEntriesAndDoesNotIncreaseBeyondThree()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m.*4 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*[)].*3 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*[)].*2 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*\\*[)].*1 more", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*\\*[)].*1 more", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanUndoSelection()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));
    Selector->initiateSelector(Player);
    command("5", Player);
    command("4", Player);
    ExpectSubStringMatch("32mFire enchantment[ ]+..0m", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*[)]", Player->caughtMessage());
    command("11", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*\\*[)]", Player->caughtMessage());
    command("undo", Player);
    ExpectSubStringMatch("32mFire enchantment[^(]+[(]\\*[)]", Player->caughtMessage());
}
