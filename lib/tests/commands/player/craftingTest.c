//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectEq("\x1b[0;36mCrafting - \x1b[0m\x1b[0;37;1mMain Menu\x1b[0m:\n"
        "[\x1b[0;31;1m1\x1b[0m] - \x1b[0;31mCraft Armor, Clothing, and Jewelry       \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m2\x1b[0m] - \x1b[0;31mCraft Artwork                            \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mCraft Musical Instrument                 \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m4\x1b[0m] - \x1b[0;31mCraft Weapons                            \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mBrew Potions                             \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mBrew Beverages and Prepare Food          \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m7\x1b[0m] - \x1b[0;31mRefine Materials                         \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m8\x1b[0m] - \x1b[0;31mImbue with Magical Effects               \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m9\x1b[0m] - \x1b[0;32mExit Crafting Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 9.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelCraftingMenuDisplaysCorrectlyWhenCraftIsExecuted()
{
    command("craft", Player);
    ExpectEq("\x1b[0;36mCrafting - \x1b[0m\x1b[0;37;1mMain Menu\x1b[0m:\n"
        "[\x1b[0;31;1m1\x1b[0m] - \x1b[0;31mCraft Armor, Clothing, and Jewelry       \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m2\x1b[0m] - \x1b[0;31mCraft Artwork                            \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mCraft Musical Instrument                 \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m4\x1b[0m] - \x1b[0;31mCraft Weapons                            \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mBrew Potions                             \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mBrew Beverages and Prepare Food          \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m7\x1b[0m] - \x1b[0;31mRefine Materials                         \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m8\x1b[0m] - \x1b[0;31mImbue with Magical Effects               \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m9\x1b[0m] - \x1b[0;32mExit Crafting Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 9.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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
