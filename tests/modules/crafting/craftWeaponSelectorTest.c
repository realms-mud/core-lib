//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithoutAnyPrereqsMetDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mCraft Weapons - [0m[0;37;1mFrom this menu, you can craft items[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mAxe                 [0m\n"
        "\t[[0;31;1m2[0m]  - [0;32mBow                 [0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mCrossbow            [0m\n"
        "\t[[0;31;1m4[0m]  - [0;32mDagger              [0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mFlail               [0m\n"
        "\t[[0;31;1m6[0m]  - [0;32mHammer              [0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mMace                [0m\n"
        "\t[[0;31;1m8[0m]  - [0;32mPole arm            [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mShield              [0m\n"
        "\t[[0;31;1m10[0m] - [0;32mSling               [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mStaff               [0m\n"
        "\t[[0;31;1m12[0m] - [0;32mSword               [0m\n"
        "\t[[0;31;1m13[0m] - [0;32mThrown              [0m\n"
        "\t[[0;31;1m14[0m] - [0;32mExit Craft Weapons Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 14.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

