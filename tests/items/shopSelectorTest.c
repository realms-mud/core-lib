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
    Selector = clone_object("/lib/items/inventory/shopSelector.c");
    Selector->setStore(load_object("/lib/environment/buildings/baseShop.c"));

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
void TopLevelMenuDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mShop - [0m[0;37;1mWelcome[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mPurchase Items      [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSell Items          [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mExit Shop Menu      [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
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
    ExpectEq("[0;36mPurchase Items - [0m[0;37;1mFrom this menu, you can view and purchase items[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mExit Buy Item Menu  [0m\n"
        "[0;32;1mYou must select a number from 1 to 1.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mThis vendor has nothing they are willing to sell to you.\n[0m",
        Player->caughtMessage());

}

/////////////////////////////////////////////////////////////////////////////
void SelectingSellItemsDisplaysSellMenu()
{
    Selector->initiateSelector(Player);
    command("2", Player);
    ExpectEq("[0;36mSell Items - [0m[0;37;1mFrom this menu, you can view and sell your character's items[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mExit Sell Item Menu [0m\n"
        "[0;32;1mYou must select a number from 1 to 1.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou have nothing you can sell to this vendor!\n[0m",
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