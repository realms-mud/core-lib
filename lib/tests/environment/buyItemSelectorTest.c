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
    Store->shopType("weapons");
    Store->shopSubType("swords");
    Store->setRandomItemsToGenerate(2);
    getDictionary("shop")->generateInventory(Store);

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
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mArmors - Medium armor\x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mWeapons - Dagger    \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mWeapons - Sword     \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mExit Buy Item Menu  \x1b[0m\n"
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
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mWeapons - Sword     \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mExit Buy Item Menu  \x1b[0m\n"
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

    ExpectSubStringMatch("You must select a number from 1 to 8",
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
    ExpectFalse(member(inherit_list(all_inventory(Player)[0]), "/lib/items/weapon.c") > -1);
    command("1", Player);

    string purchaseMessage = Player->caughtMessages()[sizeof(Player->caughtMessages()) - 2];

    ExpectSubStringMatch("You purchased.*for.*", purchaseMessage);
    ExpectEq(3, sizeof(all_inventory(Player)));

    int value = to_int(regreplace(purchaseMessage, ".*for .([0-9]+).*", "\\1", 1));
    ExpectTrue(value > 25);
    ExpectTrue(member(inherit_list(all_inventory(Player)[0]), "/lib/items/weapon.c") > -1);
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
    Store->setRandomItemsToGenerate(10);
    getDictionary("shop")->generateInventory(Store);

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
void DisplayIsCorrectForConsumables()
{
    destruct(Store);

    Store = clone_object("/lib/environment/shopInventories/baseShop.c");
    Store->name("Bob's Stuff");
    Store->welcomeMessage("Remember: Nobody outsells Bob");
    Store->shopType("potions");
    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Store);
    Selector->setStore(Store);

    Selector->initiateSelector(Player);
    move_object(Selector, Player);
    command("1", Player);

    ExpectSubStringMatch("Healing Potion.*Mana Potion",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSpecifyExactInventoryItems()
{
    destruct(Store);

    Store = clone_object("/lib/environment/shopInventories/baseShop.c");
    Store->name("Bob's Stuff");
    Store->welcomeMessage("Remember: Nobody outsells Bob");
    Store->shopType("weapons");
    Store->setRandomItemsToGenerate(40);
    Store->addInventoryItem("weapons", "staffs", ({ "rod", "staff", "wand", "ornate staff" }));
    Store->addInventoryItem("armor", "accessories", ({ "bracers", "amulet", "hat", "ring", "circlet" }));
    Store->addInventoryItem("armor", "clothing", ({ "robes", "ornate robes" }));

    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Store);
    Selector->setStore(Store);

    Selector->initiateSelector(Player);
    move_object(Selector, Player);

    ExpectSubStringMatch("Armors - Accessory.*Armors - Clothing.*Weapons - Staff",
        Player->caughtMessage());
}
