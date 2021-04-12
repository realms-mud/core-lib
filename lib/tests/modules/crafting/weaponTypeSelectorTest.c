//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    ExpectTrue(Player->initiateResearch("/lib/instances/research/crafting/weapons/craftWeapons.c"));
    ExpectTrue(Player->addResearchTree("/lib/instances/research/crafting/weapons/swords/swordsmithing.c"));
    ExpectTrue(Player->initiateResearch("/lib/instances/research/crafting/weapons/common/annealing.c"));
    ExpectTrue(Player->initiateResearch("/lib/instances/research/crafting/weapons/swords/craftLongSwords.c"));

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

    ExpectEq("\x1b[0;36mCraft Sword - \x1b[0m\x1b[0;37;1mFrom this menu, you can craft items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mBastard sword       \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mBroad sword         \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mClaymore            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mCutlass             \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mGladius             \x1b[0m     "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mGreat sword         \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mHarpe               \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mKama                \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mKatana              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mLong sword          \x1b[0m     \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mMachete             \x1b[0m     "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mOdachi              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mRapier              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mSabre               \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mScimitar            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mShort sword         \x1b[0m     \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mSickle              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mSpatha              \x1b[0m     \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mWakisashi           \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mExit Craft Sword Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 20.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddingProperPrerequisitesRemovesPFlagFromDisplay()
{
    ExpectTrue(Player->initiateResearch("/lib/instances/research/crafting/weapons/swords/craftElegantSwords.c"));
    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectEq("\x1b[0;36mCraft Sword - \x1b[0m\x1b[0;37;1mFrom this menu, you can craft items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mBastard sword       \x1b[0m\x1b[0;35m(M)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mBroad sword         \x1b[0m\x1b[0;35m(M)\x1b[0m  \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mClaymore            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mCutlass             \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mGladius             \x1b[0m     "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mGreat sword         \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mHarpe               \x1b[0m     "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mKama                \x1b[0m     \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mKatana              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mLong sword          \x1b[0m     \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mMachete             \x1b[0m     "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mOdachi              \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mRapier              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mSabre               \x1b[0m\x1b[0;35m(P,M)\x1b[0m\n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mScimitar            \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mShort sword         \x1b[0m     \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mSickle              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mSpatha              \x1b[0m     \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mWakisashi           \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mExit Craft Sword Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 20.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
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

    ExpectEq("\x1b[0;36mCraft Sword - \x1b[0m\x1b[0;37;1mFrom this menu, you can craft items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mBastard sword       \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mBroad sword         \x1b[0m     \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mClaymore            \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mCutlass             \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mGladius             \x1b[0m     "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mGreat sword         \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;31mHarpe               \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mKama                \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mKatana              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mLong sword          \x1b[0m     \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mMachete             \x1b[0m     "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mOdachi              \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mRapier              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mSabre               \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mScimitar            \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mShort sword         \x1b[0m     \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mSickle              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mSpatha              \x1b[0m     \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mWakisashi           \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mExit Craft Sword Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 20.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AddingProperPrerequisitesAndMaterialsRemovesPAndMFlagFromDisplay()
{
    ExpectTrue(Player->initiateResearch("/lib/instances/research/crafting/weapons/swords/craftElegantSwords.c"));
    object material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material->set("quantity", 10);
    move_object(material, Player);

    Selector->initiateSelector(Player);
    command("12", Player);

    ExpectEq("\x1b[0;36mCraft Sword - \x1b[0m\x1b[0;37;1mFrom this menu, you can craft items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mBastard sword       \x1b[0m     "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mBroad sword         \x1b[0m     \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mClaymore            \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mCutlass             \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mGladius             \x1b[0m     "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mGreat sword         \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mHarpe               \x1b[0m     "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mKama                \x1b[0m     \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mKatana              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mLong sword          \x1b[0m     \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mMachete             \x1b[0m     "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;31mOdachi              \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;31mRapier              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;31mSabre               \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;31mScimitar            \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mShort sword         \x1b[0m     \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;31mSickle              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mSpatha              \x1b[0m     \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;31mWakisashi           \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mExit Craft Sword Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 20.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShowsDetailsAboutWeaponWithPrerequisitesAndMaterials()
{
    Selector->initiateSelector(Player);
    command("12", Player);
    command("? 10", Player);

    ExpectSubStringMatch("This option lets you craft: long sword",
        Player->caughtMessage());

    ExpectSubStringMatch(".*Blacksmithing of 1",
        Player->caughtMessage());

    ExpectSubStringMatch("Craft Long Swords",
        Player->caughtMessage());

    ExpectSubStringMatch("Metal crafting of 1",
        Player->caughtMessage());

    ExpectSubStringMatch("Weapon smithing of 8",
        Player->caughtMessage());

    ExpectSubStringMatch("Optional.*Crystal can be",
        Player->caughtMessage());

    ExpectSubStringMatch("Leather needed.*1",
        Player->caughtMessage());

    ExpectSubStringMatch("Metal needed.*10",
        Player->caughtMessage());

    ExpectSubStringMatch("Wood needed.*1",
        Player->caughtMessage());
}
