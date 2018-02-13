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
    Player->Name("bob");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelCraftingMenuDisplaysCorrectly()
{
    command("crafting", Player);
    ExpectEq("[0;36mCrafting - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;31mCraft Armor, Clothing, and Jewelry       [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m2[0m] - [0;31mCraft Artwork                            [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m3[0m] - [0;31mCraft Musical Instrument                 [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m4[0m] - [0;31mCraft Weapons                            [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m5[0m] - [0;31mBrew Potions                             [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m6[0m] - [0;31mBrew Beverages and Prepare Food          [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m7[0m] - [0;32mRefine Materials[0m\n"
        "[[0;31;1m8[0m] - [0;31mImbue Materials with Magical Effects     [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m9[0m] - [0;32mExit Crafting Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 9.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelCraftingMenuDisplaysCorrectlyWhenCraftIsExecuted()
{
    command("craft", Player);
    ExpectEq("[0;36mCrafting - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;31mCraft Armor, Clothing, and Jewelry       [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m2[0m] - [0;31mCraft Artwork                            [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m3[0m] - [0;31mCraft Musical Instrument                 [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m4[0m] - [0;31mCraft Weapons                            [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m5[0m] - [0;31mBrew Potions                             [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m6[0m] - [0;31mBrew Beverages and Prepare Food          [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m7[0m] - [0;32mRefine Materials[0m\n"
        "[[0;31;1m8[0m] - [0;31mImbue Materials with Magical Effects     [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m9[0m] - [0;32mExit Crafting Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 9.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitRemovesSelectorFromPlayer()
{
    ExpectEq(0, sizeof(all_inventory(Player)));
    command("craft", Player);
    ExpectEq(1, sizeof(all_inventory(Player)));
    command("9", Player);
    ExpectEq(0, sizeof(all_inventory(Player)));
}