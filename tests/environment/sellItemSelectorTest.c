//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;
object Weapon;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/environment/shopInventories/sellItemSelector.c");
    Selector->setStore(load_object("/lib/environment/shopInventories/baseShop.c"));

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();

    Weapon = clone_object("/lib/tests/support/items/testSword.c");
    move_object(Weapon, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Weapon);
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mSell Items - [0m[0;37;1mFrom this menu, you can view and sell your character's items[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mWeapons             [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mExit Sell Item Menu [0m\n"
        "[0;32;1mYou must select a number from 1 to 2.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuDisplaysOptionsForEachInventoryType()
{
    move_object(clone_object("/lib/items/armor.c"), Player);
    move_object(clone_object("/lib/items/book.c"), Player);
    move_object(clone_object("/lib/items/container.c"), Player);
    move_object(clone_object("/lib/items/drink.c"), Player);
    move_object(clone_object("/lib/items/food.c"), Player);
    move_object(clone_object("/lib/items/ingredient.c"), Player);
    move_object(clone_object("/lib/items/instrument.c"), Player);
    move_object(clone_object("/lib/items/material.c"), Player);
    move_object(clone_object("/lib/items/potion.c"), Player);
    move_object(clone_object("/lib/items/scroll.c"), Player);
    move_object(clone_object("/lib/items/treasure.c"), Player);
    move_object(clone_object("/lib/items/vessel.c"), Player);
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mSell Items - [0m[0;37;1mFrom this menu, you can view and sell your character's items[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mArmors              [0m\n"
        "\t[[0;31;1m2[0m]  - [0;32mBooks               [0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mContainers          [0m\n"
        "\t[[0;31;1m4[0m]  - [0;32mDrinks              [0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mFoods               [0m\n"
        "\t[[0;31;1m6[0m]  - [0;32mIngredients         [0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mInstruments         [0m\n"
        "\t[[0;31;1m8[0m]  - [0;32mMaterials           [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mPotions             [0m\n"
        "\t[[0;31;1m10[0m] - [0;32mScrolls             [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mTreasures           [0m\n"
        "\t[[0;31;1m12[0m] - [0;32mVessels             [0m\n"
        "\t[[0;31;1m13[0m] - [0;32mWeapons             [0m\n"
        "\t[[0;31;1m14[0m] - [0;32mExit Sell Item Menu [0m\n"
        "[0;32;1mYou must select a number from 1 to 14.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuDoesNotDisplayProhibitedTypes()
{
    Selector->setProhibitedTypes(({ "drink", "food", "potion", "ingredient" }));
    move_object(clone_object("/lib/items/armor.c"), Player);
    move_object(clone_object("/lib/items/book.c"), Player);
    move_object(clone_object("/lib/items/container.c"), Player);
    move_object(clone_object("/lib/items/drink.c"), Player);
    move_object(clone_object("/lib/items/food.c"), Player);
    move_object(clone_object("/lib/items/ingredient.c"), Player);
    move_object(clone_object("/lib/items/instrument.c"), Player);
    move_object(clone_object("/lib/items/material.c"), Player);
    move_object(clone_object("/lib/items/potion.c"), Player);
    move_object(clone_object("/lib/items/scroll.c"), Player);
    move_object(clone_object("/lib/items/treasure.c"), Player);
    move_object(clone_object("/lib/items/vessel.c"), Player);
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mSell Items - [0m[0;37;1mFrom this menu, you can view and sell your character's items[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mArmors              [0m\n"
        "\t[[0;31;1m2[0m]  - [0;32mBooks               [0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mContainers          [0m\n"
        "\t[[0;31;1m4[0m]  - [0;32mInstruments         [0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mMaterials           [0m\n"
        "\t[[0;31;1m6[0m]  - [0;32mScrolls             [0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mTreasures           [0m\n"
        "\t[[0;31;1m8[0m]  - [0;32mVessels             [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mWeapons             [0m\n"
        "\t[[0;31;1m10[0m] - [0;32mExit Sell Item Menu [0m\n"
        "[0;32;1mYou must select a number from 1 to 10.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitExitsTheMenu()
{
    Selector->initiateSelector(Player);
    Selector->applySelection("2");

    ExpectSubStringMatch("You have selected 'Exit Sell Item Menu'",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeItemDisplaysCorrectMessage()
{
    Selector->initiateSelector(Player);
    Selector->applySelection("describe 1");

    ExpectSubStringMatch("This option will allow you to view your sellable\nweapons",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysSellListWithUnidentifiedItemsDenotedCorrectly()
{
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;35m (?)[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysSellListWithIdentifiedItemsDenotedCorrectly()
{
    Weapon->identify();
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Weasels[0m   [0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysSellListWithEquippedItemsDenotedCorrectly()
{
    Weapon->identify();
    Weapon->equip("sword");
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;34;1m (*)[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysSellListWithUnsellableItemsDenotedCorrectly()
{
    Weapon->set("no sell", 1);
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;31m (X)[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysSellListWithKnownCursedtemsDenotedCorrectly()
{
    Weapon->set("cursed", ([
        "equip message":"blah",
        "failed unequip message" : "halb"
    ]));
    Weapon->identify();
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;30;1m (C)[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ItemDetailsShowLongPlusValue()
{
    object sword = clone_object("/lib/tests/support/items/testSword.c");
    sword->set("name", "Sword of really long namedness");
    sword->identify();
    move_object(sword, Player);
    sword->equip("sword");

    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);
    command("? 1", Player);
    ExpectEq("[0;36mThis is the sword of weasels. It's neat.\n"
        "[0;35mThis long sword is enchanted.\n"
        "[0m\t[0;36mMaterial: [0m[0;33mGalvorn[0m\n"
        "\t[0;36mAttack: [0m[0;33m-4 to 96[0m\n"
        "\t[0;36mDamage: [0m[0;33m7 to 10[0m[0;31m [+5 magical][0m\n"
        "\t[0;36mDefense: [0m[0;33m-6 to -7[0m\n"
        "\t[0;36mEncumberance: [0m[0;33m17[0m\n"
        "[0;33m\tBonus armor class: 5\n"
        "[0m\t[0;36mWeight: [0m[0;33m7[0m\n\n"
        "[0;32mYou can sell this item for 42.[0m\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SellingItemRemovesItemFromOwnerAndSendsItToTheStoreForCorrectMoney()
{
    Selector->initiateSelector(Player);
    move_object(Selector, Player);

    string name = object_name(Weapon);
    ExpectTrue(present_clone(name, Player));
    command("1", Player);
    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;35m (?)[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());

    command("1", Player);
    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 1.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
    ExpectFalse(present_clone(name, Player));
}

/////////////////////////////////////////////////////////////////////////////
void SellingAllUnequippedDoesNotSellEquippedItems()
{
    Weapon->equip("sword");

    string name = object_name(Weapon);
    object sword = clone_object("/lib/tests/support/items/testSword.c");
    sword->set("name", "Sword of really long namedness");
    sword->identify();
    move_object(sword, Player);

    sword = clone_object("/lib/tests/support/items/testSword.c");
    sword->set("name", "Sword of Swinginess");
    sword->identify();
    move_object(sword, Player);

    Selector->initiateSelector(Player);
    move_object(Selector, Player);

    ExpectTrue(present_clone(name, Player));
    command("1", Player);
    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Swinginess[0m[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;35mSword of really l...[0m[0m\n"
        "\t[[0;31;1m3[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;34;1m (*)[0m"
        "\t[[0;31;1m4[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 5.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());

    command("4", Player);
    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;34;1m (*)[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
    ExpectTrue(present_clone(name, Player));
}

/////////////////////////////////////////////////////////////////////////////
void SellingAllUnequippedDoesNotSellCursedItems()
{
    Weapon->equip("sword");

    string name = object_name(Weapon);
    object sword = clone_object("/lib/tests/support/items/testSword.c");
    sword->set("name", "Sword of really long namedness");
    sword->identify();
    sword->set("cursed", ([
        "equip message":"blah",
        "failed unequip message": "halb"
    ]));
    move_object(sword, Player);

    sword = clone_object("/lib/tests/support/items/testSword.c");
    sword->set("name", "Sword of Swinginess");
    sword->identify();
    move_object(sword, Player);

    Selector->initiateSelector(Player);
    move_object(Selector, Player);

    ExpectTrue(present_clone(name, Player));
    command("1", Player);
    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of Swinginess[0m[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;35mSword of really l...[0m[0m[0;30;1m (C)[0m\n"
        "\t[[0;31;1m3[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;34;1m (*)[0m"
        "\t[[0;31;1m4[0m] - [0;32m[0;30;1mSell all unused[0m    [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 5.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());

    command("4", Player);
    ExpectEq("[0;36mSell Items - [0m[0;37;1mSelect an item to sell[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32m[0;35mSword of really l...[0m[0m[0;30;1m (C)[0m"
        "\t[[0;31;1m2[0m] - [0;32m[0;35mSword of Weasels[0m   [0m[0;34;1m (*)[0m\n"
        "\t[[0;31;1m3[0m] - [0;32m[0;30;1mSell all unused[0m    [0m"
        "\t[[0;31;1m4[0m] - [0;32mReturn to previous menu       [0m\n"
        "[0;32;1mYou must select a number from 1 to 4.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
    ExpectTrue(present_clone(name, Player));
}
