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
    Player->colorConfiguration("3-bit");
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

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mFrom this menu, you can view and sell your character's items\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mWeapons             \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mExit Sell Item Menu \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 2.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mFrom this menu, you can view and sell your character's items\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mArmors              \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mBooks               \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mContainers          \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mDrinks              \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mFoods               \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mIngredients         \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mInstruments         \x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mMaterials           \x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mPotions             \x1b[0m\n"
        "\t[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mScrolls             \x1b[0m\n"
        "\t[\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mTreasures           \x1b[0m\n"
        "\t[\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mVessels             \x1b[0m\n"
        "\t[\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mWeapons             \x1b[0m\n"
        "\t[\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mExit Sell Item Menu \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 14.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mFrom this menu, you can view and sell your character's items\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mArmors              \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mBooks               \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mContainers          \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mInstruments         \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mMaterials           \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mScrolls             \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mTreasures           \x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mVessels             \x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mWeapons             \x1b[0m\n"
        "\t[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mExit Sell Item Menu \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 10.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;35m (?)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UnicodeDisplaysSellListWithUnidentifiedItemsDenotedCorrectly()
{
    Player->charsetConfiguration("unicode");    
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;35m (\xe2\x81\x87)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}
/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysSellListWithIdentifiedItemsDenotedCorrectly()
{
    Weapon->identify();
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysSellListWithEquippedItemsDenotedCorrectly()
{
    Weapon->identify();
    Weapon->equip("sword");
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UnicodeDisplaysSellListWithEquippedItemsDenotedCorrectly()
{
    Player->charsetConfiguration("unicode");
    Weapon->identify();
    Weapon->equip("sword");
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;34;1m (\xe2\x80\xa0)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysSellListWithUnsellableItemsDenotedCorrectly()
{
    Weapon->set("no sell", 1);
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;31m (X)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UnicodeDisplaysSellListWithUnsellableItemsDenotedCorrectly()
{
    Player->charsetConfiguration("unicode");
    Weapon->set("no sell", 1);
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;31m (X)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;30;1m (C)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UnicodeDisplaysSellListWithKnownCursedtemsDenotedCorrectly()
{
    Player->charsetConfiguration("unicode");
    Weapon->set("cursed", ([
        "equip message":"blah",
        "failed unequip message" : "halb"
    ]));
    Weapon->identify();
    Selector->initiateSelector(Player);
    Selector->applySelection("1");

    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;30;1m (\xe2\x98\xa0)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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
    ExpectEq("\x1b[0;36mThis is the sword of weasels. It's neat.\n"
        "\x1b[0;35mThis long sword is enchanted.\n"
        "\x1b[0m\x1b[0;36m\tMaterial: \x1b[0m\x1b[0;33mGalvorn\x1b[0m\n"
        "\x1b[0;36m\tAttack: \x1b[0m\x1b[0;33m10\x1b[0m\x1b[0;33m to 110\x1b[0m\n"
        "\x1b[0;36m\tDamage: \x1b[0m\x1b[0;33m15\x1b[0m\x1b[0;33m to 20\x1b[0m\x1b[0;31m [+5 magical]\x1b[0m\n"
        "\x1b[0;36m\tDefense: \x1b[0m\x1b[0;33m1\x1b[0m\x1b[0;33m to 2\x1b[0m\n"
        "\x1b[0;36m\tEncumberance: \x1b[0m\x1b[0;33m7\x1b[0m\n"
        "\x1b[0;33m\tBonus armor class: 5\n"
        "\x1b[0m\x1b[0;36m\tWeight: \x1b[0m\x1b[0;33m7\x1b[0m\n\n"
        "\x1b[0;32mYou can sell this item for 42.\x1b[0m\n\x1b[0m",
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
    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;35m (?)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());

    command("1", Player);
    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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
    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Swinginess\x1b[0m\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of really l...\x1b[0m\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 5.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());

    command("4", Player);
    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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
    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Swinginess\x1b[0m\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of really l...\x1b[0m\x1b[0m\x1b[0;30;1m (C)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 5.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());

    command("4", Player);
    ExpectEq("\x1b[0;36mSell Items - \x1b[0m\x1b[0;37;1mSelect an item to sell\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of really l...\x1b[0m\x1b[0m\x1b[0;30;1m (C)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels\x1b[0m   \x1b[0m\x1b[0;34;1m (*)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32m\x1b[0;30;1mSell all unused\x1b[0m    \x1b[0m"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mReturn to previous menu       \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 4.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
    ExpectTrue(present_clone(name, Player));
}
