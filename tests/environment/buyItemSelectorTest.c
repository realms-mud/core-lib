//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;
object Store;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "SetUpStoreInventory" });
}

/////////////////////////////////////////////////////////////////////////////
void SetUpStoreInventory()
{
    destruct(Store);

    Store = clone_object("/lib/environment/shopInventories/baseShop.c");
    Store->name("Bob's Swords");
    Store->welcomeMessage("Remember: Nobody outsells Bob");
    Store->shopType("weapons");
    Store->shopSubType("swords");

    Store->storeItem(clone_object("/lib/instances/items/weapons/swords/bastard-sword.c"));

    object weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    weapon->identify();
    Store->storeItem(weapon);
    Selector->setStore(Store);

    weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    weapon->identify();
    weapon->set("material", "galvorn");
    weapon->set("name", "Sword of Weasels");
    weapon->set("bonus strength", 1);
    Store->storeItem(weapon);
    Selector->setStore(Store);

    weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    weapon->identify();
    weapon->set("material", "admantite");
    weapon->set("name", "Admantite Sword");
    weapon->set("craftsmanship", 60);
    Store->storeItem(weapon);
    Selector->setStore(Store);

    weapon = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    weapon->identify();
    weapon->set("material", "admantite");
    weapon->set("name", "Admantite Sword");
    Store->storeItem(weapon);
    Selector->setStore(Store);

    weapon = clone_object("/lib/instances/items/weapons/swords/claymore.c");
    weapon->identify();
    weapon->set("material", "admantite");
    weapon->set("name", "Sword of Really Long Names");
    weapon->set("bonus strength", 5);
    weapon->set("bonus damage", 5);
    Store->storeItem(weapon);
    Selector->setStore(Store);

    weapon = clone_object("/lib/instances/items/weapons/swords/katana.c");
    weapon->identify();
    weapon->set("material", "kirdarium");
    weapon->set("name", "Sword of the Grebes");
    weapon->set("craftsmanship", 80);
    Store->storeItem(weapon);
    Selector->setStore(Store);
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Store = clone_object("/lib/environment/shopInventories/baseShop.c");
    Store->name("Bob's Swords");
    Store->welcomeMessage("Remember: Nobody outsells Bob");
    Store->shopType("weapons");
    Store->shopSubType("swords");
    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Store);

    Selector = clone_object("/lib/environment/shopInventories/buyItemSelector.c");
    Selector->setStore(Store);

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Store);
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuDisplaysCorrectly()
{
    object armor = clone_object("/lib/items/armor.c");
    armor->set("name", "Chainmail");
    armor->set("short", "Chainmail");
    armor->set("blueprint", "chainmail");

    Store->storeItem(armor);
    Store->storeItem(clone_object("/lib/instances/items/weapons/daggers/dagger.c"));
    Selector->initiateSelector(Player);

    ExpectEq("\x1b[0;36mPurchase Items - \x1b[0m\x1b[0;37;1mFrom this menu, you can view and purchase items\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mArmors - Medium armor\x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mWeapons - Dagger    \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mWeapons - Sword     \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mExit Buy Item Menu  \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 4.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitExitsTheMenu()
{
    Selector->initiateSelector(Player);

    ExpectEq("\x1b[0;36mPurchase Items - \x1b[0m\x1b[0;37;1mFrom this menu, you can view and purchase items\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mWeapons - Sword     \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mExit Buy Item Menu  \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 2.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());

    Selector->applySelection("2");

    ExpectSubStringMatch("You have selected 'Exit Buy Item Menu'",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeItemDisplaysCorrectMessage()
{
    Selector->initiateSelector(Player);
    Selector->applySelection("describe 1");

    ExpectSubStringMatch("his option will allow you to view sword type weapons that are for sale",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubMenuDisplaysBuyList()
{
    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    ExpectSubStringMatch("You must select a number from 1 to 21",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShowsItemDetails()
{
    destruct(Store);
    Store = clone_object("/lib/environment/shopInventories/baseShop.c");
    Store->name("Bob's Swords");
    Store->welcomeMessage("Remember: Nobody outsells Bob");
    Store->shopType("weapons");
    Store->shopSubType("swords");
    Store->setRandomItemsToGenerate(0);
    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Store);
    Selector->setStore(Store);

    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);
    command("? 1", Player);

    ExpectSubStringMatch("bastard sword.*Material.*Attack.*Damage.*Defense.*You can buy this item for 650",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PurchaseWithInsufficientFundsFails()
{
    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);
    command("1", Player);

    ExpectSubStringMatch("You do not have the funds for that",
        Player->caughtMessages()[sizeof(Player->caughtMessages()) - 2]);
}

/////////////////////////////////////////////////////////////////////////////
void PurchaseWithSufficientFundsSubtractsMoneyAndAddsItemToPlayerInventory()
{
    Player->addMoney(1000000);
    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    ExpectEq(1000000, Player->Money());
    ExpectEq(2, sizeof(all_inventory(Player)));
    ExpectFalse(member(inherit_list(all_inventory(Player)[0]), "lib/items/weapon.c") > -1);
    command("1", Player);

    string purchaseMessage = Player->caughtMessages()[sizeof(Player->caughtMessages()) - 2];

    ExpectSubStringMatch("You purchased.*for.*", purchaseMessage);
    ExpectEq(3, sizeof(all_inventory(Player)));

    int value = to_int(regreplace(purchaseMessage, ".*for .([0-9]+).*", "\\1", 1));
    ExpectTrue(value > 25);
    ExpectTrue(member(inherit_list(all_inventory(Player)[0]), "lib/items/weapon.c") > -1);
    ExpectTrue(mappingp(all_inventory(Player)[0]->query("crafting materials")));
    ExpectEq(1000000 - value, Player->Money());
}

/////////////////////////////////////////////////////////////////////////////
void PurchaseOfPermanentItemDoesNotRemoveFromStore()
{
    destruct(Store);
    Store = clone_object("/lib/environment/shopInventories/baseShop.c");
    Store->name("Bob's Swords");
    Store->welcomeMessage("Remember: Nobody outsells Bob");
    Store->shopType("weapons");
    Store->shopSubType("swords");
    Store->setRandomItemsToGenerate(0);
    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Store);
    Selector->setStore(Store);

    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    Player->addMoney(1000000);
    ExpectEq(1000000, Player->Money());

    string initialMessage = Player->caughtMessage();
    command("1", Player);
    ExpectTrue(1000000 > Player->Money());
    ExpectEq(initialMessage, Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void PurchaseOfNonPermanentItemRemovesItFromStore()
{
    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    Player->addMoney(1000000);
    ExpectEq(1000000, Player->Money());
    ExpectEq(2, sizeof(all_inventory(Player)));

    string initialMessage = Player->caughtMessage();
    command("1", Player);
    command("2", Player);
    command("3", Player);
    command("4", Player);
    command("5", Player);
    command("6", Player);
    command("7", Player);
    command("8", Player);
    command("9", Player);
    command("10", Player);
    ExpectTrue(1000000 > Player->Money());
    ExpectEq(12, sizeof(all_inventory(Player)));
    ExpectFalse(initialMessage == Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayIsCorrectWithNoColorSelected()
{
    SetUpStoreInventory();
    Player->colorConfiguration("none");
    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    ExpectEq("Buy Items - Select an item to buy:\n"
        "-=-=-=-=-=-=-= Name =-=-=-=-=-=-=- Cost -=-=-= Item Details =-=-=-=-=-=-=-=-=-\n"
        "[1] - Bastard sword                 650    This item has not been identified\n"
        "[2] - Sword of Really L... (P)    23250    Damage: 21, Defense:  4, Attack:  8\n"
        "[3] - Sword of the Grebes  (C)    18337    Damage: 21, Defense:  4, Attack: 21\n"
        "[4] - Long sword                    450    Damage: 10, Defense:  2, Attack:  5\n"
        "[5] - Sword of Weasels     (E)     7750    Damage: 18, Defense:  2, Attack: 10\n"
        "[6] - Admantite Sword      (M)     3975    Damage: 21, Defense:  8, Attack: 14\n"
        "[7] - Admantite Sword              3450    Damage: 15, Defense:  2, Attack:  8\n"
        "[8] - Return to previous menu\n"
        "You must select a number from 1 to 8.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "Items with a (C) to the right of their name are particularly well-crafted.\n"
        "Items with a (M) to the right of their name are masterwork items.\n"
        "Items with a (E) to the right of their name are enchanted.\n"
        "Items with a (P) to the right of their name are enchanted with powerful magic.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayIsCorrectWithThreeBitColorSelected()
{
    SetUpStoreInventory();
    Player->colorConfiguration("3-bit");
    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mBuy Items - \x1b[0m\x1b[0;37;1mSelect an item to buy:\n"
        "\x1b[0;31m-=-=-=-=-=-=-= Name =-=-=-=-=-=-=- Cost -=-=-= Item Details =-=-=-=-=-=-=-=-=-\x1b[0m\x1b[0m\n"
        "[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32m\x1b[0;37;1mBastard sword          \x1b[0m\x1b[0;32m      650\x1b[0m\x1b[0m    \x1b[0;30;1mThis item has not been identified\x1b[0m\n"
        "[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32m\x1b[0;35;1mSword of Really L...   \x1b[0m\x1b[0;32m    23250\x1b[0m\x1b[0m    \x1b[0;36mDamage: \x1b[0m\x1b[0;33m21\x1b[0m, \x1b[0;36mDefense: \x1b[0m\x1b[0;33m 4\x1b[0m, \x1b[0;36mAttack: \x1b[0m\x1b[0;33m 8\x1b[0m\n"
        "[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32m\x1b[0;32mSword of the Grebes    \x1b[0m\x1b[0;32m    18337\x1b[0m\x1b[0m    \x1b[0;36mDamage: \x1b[0m\x1b[0;33m21\x1b[0m, \x1b[0;36mDefense: \x1b[0m\x1b[0;33m 4\x1b[0m, \x1b[0;36mAttack: \x1b[0m\x1b[0;33m21\x1b[0m\n"
        "[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32m\x1b[0;37;1mLong sword             \x1b[0m\x1b[0;32m      450\x1b[0m\x1b[0m    \x1b[0;36mDamage: \x1b[0m\x1b[0;33m10\x1b[0m, \x1b[0;36mDefense: \x1b[0m\x1b[0;33m 2\x1b[0m, \x1b[0;36mAttack: \x1b[0m\x1b[0;33m 5\x1b[0m\n"
        "[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32m\x1b[0;35mSword of Weasels       \x1b[0m\x1b[0;32m     7750\x1b[0m\x1b[0m    \x1b[0;36mDamage: \x1b[0m\x1b[0;33m18\x1b[0m, \x1b[0;36mDefense: \x1b[0m\x1b[0;33m 2\x1b[0m, \x1b[0;36mAttack: \x1b[0m\x1b[0;33m10\x1b[0m\n"
        "[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32m\x1b[0;32;1mAdmantite Sword        \x1b[0m\x1b[0;32m     3975\x1b[0m\x1b[0m    \x1b[0;36mDamage: \x1b[0m\x1b[0;33m21\x1b[0m, \x1b[0;36mDefense: \x1b[0m\x1b[0;33m 8\x1b[0m, \x1b[0;36mAttack: \x1b[0m\x1b[0;33m14\x1b[0m\n"
        "[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32m\x1b[0;37;1mAdmantite Sword        \x1b[0m\x1b[0;32m     3450\x1b[0m\x1b[0m    \x1b[0;36mDamage: \x1b[0m\x1b[0;33m15\x1b[0m, \x1b[0;36mDefense: \x1b[0m\x1b[0;33m 2\x1b[0m, \x1b[0;36mAttack: \x1b[0m\x1b[0;33m 8\x1b[0m\n"
        "[\x1b[0;31;1m8\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 8.\n"
        "\x1b[0m\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n"
        "\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayIsCorrectWithEightBitColorSelected()
{
    SetUpStoreInventory();
    Player->colorConfiguration("8-bit");
    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    ExpectEq("\x1b[0;38;5;80mBuy Items - \x1b[0m\x1b[0;38;5;15;1mSelect an item to buy:\n"
        "\x1b[0;38;5;9m-=-=-=-=-=-=-= Name =-=-=-=-=-=-=- Cost -=-=-= Item Details =-=-=-=-=-=-=-=-=-\x1b[0m\x1b[0m\n"
        "[\x1b[0;38;5;9;1m1\x1b[0m] - \x1b[0;38;5;2m\x1b[0;38;5;231;1mBastard sword          \x1b[0m\x1b[0;38;5;2m      650\x1b[0m\x1b[0m    \x1b[0;38;5;238;1mThis item has not been identified\x1b[0m\n"
        "[\x1b[0;38;5;9;1m2\x1b[0m] - \x1b[0;38;5;2m\x1b[0;38;5;32;1mSword of Really L...   \x1b[0m\x1b[0;38;5;2m    23250\x1b[0m\x1b[0m    \x1b[0;38;5;80mDamage: \x1b[0m\x1b[0;38;5;190m21\x1b[0m, \x1b[0;38;5;80mDefense: \x1b[0m\x1b[0;38;5;190m 4\x1b[0m, \x1b[0;38;5;80mAttack: \x1b[0m\x1b[0;38;5;190m 8\x1b[0m\n"
        "[\x1b[0;38;5;9;1m3\x1b[0m] - \x1b[0;38;5;2m\x1b[0;38;5;144mSword of the Grebes    \x1b[0m\x1b[0;38;5;2m    18337\x1b[0m\x1b[0m    \x1b[0;38;5;80mDamage: \x1b[0m\x1b[0;38;5;190m21\x1b[0m, \x1b[0;38;5;80mDefense: \x1b[0m\x1b[0;38;5;190m 4\x1b[0m, \x1b[0;38;5;80mAttack: \x1b[0m\x1b[0;38;5;190m21\x1b[0m\n"
        "[\x1b[0;38;5;9;1m4\x1b[0m] - \x1b[0;38;5;2m\x1b[0;38;5;231;1mLong sword             \x1b[0m\x1b[0;38;5;2m      450\x1b[0m\x1b[0m    \x1b[0;38;5;80mDamage: \x1b[0m\x1b[0;38;5;190m10\x1b[0m, \x1b[0;38;5;80mDefense: \x1b[0m\x1b[0;38;5;190m 2\x1b[0m, \x1b[0;38;5;80mAttack: \x1b[0m\x1b[0;38;5;190m 5\x1b[0m\n"
        "[\x1b[0;38;5;9;1m5\x1b[0m] - \x1b[0;38;5;2m\x1b[0;38;5;31mSword of Weasels       \x1b[0m\x1b[0;38;5;2m     7750\x1b[0m\x1b[0m    \x1b[0;38;5;80mDamage: \x1b[0m\x1b[0;38;5;190m18\x1b[0m, \x1b[0;38;5;80mDefense: \x1b[0m\x1b[0;38;5;190m 2\x1b[0m, \x1b[0;38;5;80mAttack: \x1b[0m\x1b[0;38;5;190m10\x1b[0m\n"
        "[\x1b[0;38;5;9;1m6\x1b[0m] - \x1b[0;38;5;2m\x1b[0;38;5;149;1mAdmantite Sword        \x1b[0m\x1b[0;38;5;2m     3975\x1b[0m\x1b[0m    \x1b[0;38;5;80mDamage: \x1b[0m\x1b[0;38;5;190m21\x1b[0m, \x1b[0;38;5;80mDefense: \x1b[0m\x1b[0;38;5;190m 8\x1b[0m, \x1b[0;38;5;80mAttack: \x1b[0m\x1b[0;38;5;190m14\x1b[0m\n"
        "[\x1b[0;38;5;9;1m7\x1b[0m] - \x1b[0;38;5;2m\x1b[0;38;5;231;1mAdmantite Sword        \x1b[0m\x1b[0;38;5;2m     3450\x1b[0m\x1b[0m    \x1b[0;38;5;80mDamage: \x1b[0m\x1b[0;38;5;190m15\x1b[0m, \x1b[0;38;5;80mDefense: \x1b[0m\x1b[0;38;5;190m 2\x1b[0m, \x1b[0;38;5;80mAttack: \x1b[0m\x1b[0;38;5;190m 8\x1b[0m\n"
        "[\x1b[0;38;5;9;1m8\x1b[0m] - \x1b[0;38;5;2mReturn to previous menu\x1b[0m\n"
        "\x1b[0;38;5;2;1mYou must select a number from 1 to 8.\n"
        "\x1b[0m\x1b[0;38;5;144mType 'exit' if you do not wish to make a selection at this time.\n"
        "\x1b[0m\x1b[0;38;5;144mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n\x1b[0m\x1b[0;38;5;2;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DisplayIsCorrectWithTwnetyFourBitColorSelected()
{
    SetUpStoreInventory();
    Player->colorConfiguration("24-bit");
    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    ExpectEq("\x1b[0;38;2;180;180;190mBuy Items - \x1b[0m\x1b[0;38;2;255;255;255;1mSelect an item to buy:\n"
        "\x1b[0;38;2;200;0;0m-=-=-=-=-=-=-= Name =-=-=-=-=-=-=- Cost -=-=-= Item Details =-=-=-=-=-=-=-=-=-\x1b[0m\x1b[0m\n"
        "[\x1b[0;38;2;220;40;0;1m1\x1b[0m] - \x1b[0;38;2;170;180;110m\x1b[0;38;2;255;255;255;1mBastard sword          \x1b[0m\x1b[0;38;2;170;180;110m      650\x1b[0m\x1b[0m    \x1b[0;38;2;70;60;60;1mThis item has not been identified\x1b[0m\n"
        "[\x1b[0;38;2;220;40;0;1m2\x1b[0m] - \x1b[0;38;2;170;180;110m\x1b[0;38;2;80;155;195;1mSword of Really L...   \x1b[0m\x1b[0;38;2;170;180;110m    23250\x1b[0m\x1b[0m    \x1b[0;38;2;180;180;190mDamage: \x1b[0m\x1b[0;38;2;200;200;0m21\x1b[0m, \x1b[0;38;2;180;180;190mDefense: \x1b[0m\x1b[0;38;2;200;200;0m 4\x1b[0m, \x1b[0;38;2;180;180;190mAttack: \x1b[0m\x1b[0;38;2;200;200;0m 8\x1b[0m\n"
        "[\x1b[0;38;2;220;40;0;1m3\x1b[0m] - \x1b[0;38;2;170;180;110m\x1b[0;38;2;100;180;150mSword of the Grebes    \x1b[0m\x1b[0;38;2;170;180;110m    18337\x1b[0m\x1b[0m    \x1b[0;38;2;180;180;190mDamage: \x1b[0m\x1b[0;38;2;200;200;0m21\x1b[0m, \x1b[0;38;2;180;180;190mDefense: \x1b[0m\x1b[0;38;2;200;200;0m 4\x1b[0m, \x1b[0;38;2;180;180;190mAttack: \x1b[0m\x1b[0;38;2;200;200;0m21\x1b[0m\n"
        "[\x1b[0;38;2;220;40;0;1m4\x1b[0m] - \x1b[0;38;2;170;180;110m\x1b[0;38;2;255;255;255;1mLong sword             \x1b[0m\x1b[0;38;2;170;180;110m      450\x1b[0m\x1b[0m    \x1b[0;38;2;180;180;190mDamage: \x1b[0m\x1b[0;38;2;200;200;0m10\x1b[0m, \x1b[0;38;2;180;180;190mDefense: \x1b[0m\x1b[0;38;2;200;200;0m 2\x1b[0m, \x1b[0;38;2;180;180;190mAttack: \x1b[0m\x1b[0;38;2;200;200;0m 5\x1b[0m\n"
        "[\x1b[0;38;2;220;40;0;1m5\x1b[0m] - \x1b[0;38;2;170;180;110m\x1b[0;38;2;80;155;175mSword of Weasels       \x1b[0m\x1b[0;38;2;170;180;110m     7750\x1b[0m\x1b[0m    \x1b[0;38;2;180;180;190mDamage: \x1b[0m\x1b[0;38;2;200;200;0m18\x1b[0m, \x1b[0;38;2;180;180;190mDefense: \x1b[0m\x1b[0;38;2;200;200;0m 2\x1b[0m, \x1b[0;38;2;180;180;190mAttack: \x1b[0m\x1b[0;38;2;200;200;0m10\x1b[0m\n"
        "[\x1b[0;38;2;220;40;0;1m6\x1b[0m] - \x1b[0;38;2;170;180;110m\x1b[0;38;2;100;220;150;1mAdmantite Sword        \x1b[0m\x1b[0;38;2;170;180;110m     3975\x1b[0m\x1b[0m    \x1b[0;38;2;180;180;190mDamage: \x1b[0m\x1b[0;38;2;200;200;0m21\x1b[0m, \x1b[0;38;2;180;180;190mDefense: \x1b[0m\x1b[0;38;2;200;200;0m 8\x1b[0m, \x1b[0;38;2;180;180;190mAttack: \x1b[0m\x1b[0;38;2;200;200;0m14\x1b[0m\n"
        "[\x1b[0;38;2;220;40;0;1m7\x1b[0m] - \x1b[0;38;2;170;180;110m\x1b[0;38;2;255;255;255;1mAdmantite Sword        \x1b[0m\x1b[0;38;2;170;180;110m     3450\x1b[0m\x1b[0m    \x1b[0;38;2;180;180;190mDamage: \x1b[0m\x1b[0;38;2;200;200;0m15\x1b[0m, \x1b[0;38;2;180;180;190mDefense: \x1b[0m\x1b[0;38;2;200;200;0m 2\x1b[0m, \x1b[0;38;2;180;180;190mAttack: \x1b[0m\x1b[0;38;2;200;200;0m 8\x1b[0m\n"
        "[\x1b[0;38;2;220;40;0;1m8\x1b[0m] - \x1b[0;38;2;170;180;110mReturn to previous menu\x1b[0m\n"
        "\x1b[0;38;2;160;220;60;1mYou must select a number from 1 to 8.\n"
        "\x1b[0m\x1b[0;38;2;100;180;150mType 'exit' if you do not wish to make a selection at this time.\n"
        "\x1b[0m\x1b[0;38;2;100;180;150mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n\x1b[0m\x1b[0;38;2;160;220;60;1m\x1b[0m",
        Player->caughtMessage());
}
