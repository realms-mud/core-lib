//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelShopMenuDisplaysCorrectly()
{
    move_object(Player, load_object("/lib/tests/support/environment/fakeShop.c"));

    command("shop", Player);
    ExpectEq("\x1b[0;36mThe Swordsmith - \x1b[0m\x1b[0;37;1mWelcome to the swordsmith's shop\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mPurchase Items      \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSell Items          \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mExit Shop Menu      \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotShopInNonShopEnvironment()
{
    move_object(Player, load_object("/lib/tests/support/environment/fakeEnvironment.c"));

    command("shop", Player);
    ExpectEq("What?\n", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanNavigateToSubMenus()
{
    move_object(Player, load_object("/lib/tests/support/environment/fakeShop.c"));

    command("shop", Player);
    command("1", Player);
    ExpectEq("\x1b[0;36mPurchase Items - \x1b[0m\x1b[0;37;1mFrom this menu, you can view and purchase items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mWeapons - Sword     \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mExit Buy Item Menu  \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 2.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player.caughtMessage());
}