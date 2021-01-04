//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;
object Store;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Store = clone_object("/lib/environment/shopInventories/baseShop.c");
    Store->name("Bob's Swords");
    Store->welcomeMessage("Remember: Nobody outsells Bob");
    Selector = clone_object("/lib/environment/shopInventories/shopSelector.c");
    Selector->setStore(Store);

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
    destruct(Store);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("\x1b[0;36mBob's Swords - \x1b[0m\x1b[0;37;1mRemember: Nobody outsells Bob\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mPurchase Items      \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSell Items          \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mExit Shop Menu      \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionsAreDisplayed()
{
    Selector->initiateSelector(Player);
    command("? 1", Player);
    ExpectSubStringMatch("This options lets you purchase items from the store",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingPurchaseDisplaysBuyMenu()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    ExpectEq("\x1b[0;36mPurchase Items - \x1b[0m\x1b[0;37;1mFrom this menu, you can view and purchase items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mExit Buy Item Menu  \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mThis vendor has nothing they are willing to sell to you.\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingSellItemsDisplaysSellMenu()
{
    Selector->initiateSelector(Player);
    command("2", Player);
    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mFrom this menu, you can view and sell your character's items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mExit Sell Item Menu \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou have nothing you can sell to this vendor!\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitExitsSelector()
{
    Selector->initiateSelector(Player);
    command("3", Player);
    ExpectSubStringMatch("You have selected 'Exit Shop Menu'",
        Player->caughtMessage());
}
