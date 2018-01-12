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
    Selector = clone_object("/lib/modules/crafting/craftItemSelector.c");
    Selector->setType("weapons");
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
    Player->addResearchPoints(20);

    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 6);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material->set("quantity", 10);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/iron.c");
    material->set("quantity", 3);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/iron.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/wood/koa.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/leather/pegasus-leather.c");
    material->set("quantity", 5);
    move_object(material, Player);

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftWeapons.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftBasicSwords.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftLongSwords.c"));

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuDisplaysWithMissingPrerequisitesAndMaterials()
{
    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectEq("[0;36mCraft Sword - [0m[0;37;1mFrom this menu, you can craft items[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mBastard sword       [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m2[0m]  - [0;31mBroad sword         [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m3[0m]  - [0;31mClaymore            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m4[0m]  - [0;31mCutlass             [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;32mGladius             [0m     "
        "    [[0;31;1m6[0m]  - [0;31mGreat sword         [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m7[0m]  - [0;31mHarpe               [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m8[0m]  - [0;31mKama                [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m9[0m]  - [0;31mKatana              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;32mLong sword          [0m     \n"
        "    [[0;31;1m11[0m] - [0;32mMachete             [0m     "
        "    [[0;31;1m12[0m] - [0;31mOdachi              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m13[0m] - [0;31mRapier              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m14[0m] - [0;31mSabre               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m15[0m] - [0;31mScimitar            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m16[0m] - [0;32mShort sword         [0m     \n"
        "    [[0;31;1m17[0m] - [0;31mSickle              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m18[0m] - [0;32mSpatha              [0m     \n"
        "    [[0;31;1m19[0m] - [0;31mWakisashi           [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;32mExit Craft Sword Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 20.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddingProperPrerequisitesRemovesPFlagFromDisplay()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftElegantSwords.c"));
    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectEq("[0;36mCraft Sword - [0m[0;37;1mFrom this menu, you can craft items[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mBastard sword       [0m[0;34;1m([0;35mM[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;31mBroad sword         [0m[0;34;1m([0;35mM[0;34;1m)[0m  \n"
        "    [[0;31;1m3[0m]  - [0;31mClaymore            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m4[0m]  - [0;31mCutlass             [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;32mGladius             [0m     "
        "    [[0;31;1m6[0m]  - [0;31mGreat sword         [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m7[0m]  - [0;32mHarpe               [0m     "
        "    [[0;31;1m8[0m]  - [0;32mKama                [0m     \n"
        "    [[0;31;1m9[0m]  - [0;31mKatana              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;32mLong sword          [0m     \n"
        "    [[0;31;1m11[0m] - [0;32mMachete             [0m     "
        "    [[0;31;1m12[0m] - [0;31mOdachi              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m13[0m] - [0;31mRapier              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m14[0m] - [0;31mSabre               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m15[0m] - [0;31mScimitar            [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m16[0m] - [0;32mShort sword         [0m     \n"
        "    [[0;31;1m17[0m] - [0;31mSickle              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m18[0m] - [0;32mSpatha              [0m     \n"
        "    [[0;31;1m19[0m] - [0;31mWakisashi           [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;32mExit Craft Sword Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 20.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddingProperMaterialsRemovesMFlagFromDisplay()
{
    object material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material->set("quantity", 10);
    move_object(material, Player);

    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectEq("[0;36mCraft Sword - [0m[0;37;1mFrom this menu, you can craft items[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mBastard sword       [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;32mBroad sword         [0m     \n"
        "    [[0;31;1m3[0m]  - [0;31mClaymore            [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m4[0m]  - [0;31mCutlass             [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;32mGladius             [0m     "
        "    [[0;31;1m6[0m]  - [0;31mGreat sword         [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m]  - [0;31mHarpe               [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m8[0m]  - [0;31mKama                [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m9[0m]  - [0;31mKatana              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;32mLong sword          [0m     \n"
        "    [[0;31;1m11[0m] - [0;32mMachete             [0m     "
        "    [[0;31;1m12[0m] - [0;31mOdachi              [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m13[0m] - [0;31mRapier              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m14[0m] - [0;31mSabre               [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m15[0m] - [0;31mScimitar            [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m16[0m] - [0;32mShort sword         [0m     \n"
        "    [[0;31;1m17[0m] - [0;31mSickle              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m18[0m] - [0;32mSpatha              [0m     \n"
        "    [[0;31;1m19[0m] - [0;31mWakisashi           [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;32mExit Craft Sword Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 20.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddingProperPrerequisitesAndMaterialsRemovesPAndMFlagFromDisplay()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftElegantSwords.c"));
    object material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material->set("quantity", 10);
    move_object(material, Player);

    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectEq("[0;36mCraft Sword - [0m[0;37;1mFrom this menu, you can craft items[0m:\n"
        "    [[0;31;1m1[0m]  - [0;32mBastard sword       [0m     "
        "    [[0;31;1m2[0m]  - [0;32mBroad sword         [0m     \n"
        "    [[0;31;1m3[0m]  - [0;31mClaymore            [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m4[0m]  - [0;31mCutlass             [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;32mGladius             [0m     "
        "    [[0;31;1m6[0m]  - [0;31mGreat sword         [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m]  - [0;32mHarpe               [0m     "
        "    [[0;31;1m8[0m]  - [0;32mKama                [0m     \n"
        "    [[0;31;1m9[0m]  - [0;31mKatana              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;32mLong sword          [0m     \n"
        "    [[0;31;1m11[0m] - [0;32mMachete             [0m     "
        "    [[0;31;1m12[0m] - [0;31mOdachi              [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m13[0m] - [0;31mRapier              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m14[0m] - [0;31mSabre               [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m15[0m] - [0;31mScimitar            [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m16[0m] - [0;32mShort sword         [0m     \n"
        "    [[0;31;1m17[0m] - [0;31mSickle              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m18[0m] - [0;32mSpatha              [0m     \n"
        "    [[0;31;1m19[0m] - [0;31mWakisashi           [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;32mExit Craft Sword Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 20.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShowsDetailsAboutWeaponWithPrerequisitesAndMaterials()
{
    Selector->initiateSelector(Player);
    command("12", Player);
    command("? 10", Player);

    ExpectSubStringMatch("This option lets you craft: long sword"
        ".*Blacksmithing of 1.*Craft Basic Swords.*Metal crafting of 1"
        ".*Weapon smithing of 8.*Optional.*crystal can be"
        ".*Leather needed.*1.*Metal needed.*10.*Wood needed.*1",
        Player->caughtMessage());
}
