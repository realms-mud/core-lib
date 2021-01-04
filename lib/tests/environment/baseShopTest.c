//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Shop;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Shop = clone_object("/lib/environment/shopInventories/baseShop.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Shop);
}

/////////////////////////////////////////////////////////////////////////////
void TypeReturnsShop()
{
    ExpectEq("shop", Shop->Type());
}

/////////////////////////////////////////////////////////////////////////////
void NameSetsAndGetsName()
{
    ExpectEq("Shop", Shop->name());
    ExpectEq("Bob's Shop", Shop->name("Bob's Shop"));
    ExpectEq("Bob's Shop", Shop->name());
}

/////////////////////////////////////////////////////////////////////////////
void WelcomeMessageSetsAndGetsWelcomeMessage()
{
    ExpectEq("Welcome", Shop->welcomeMessage());
    ExpectEq("Bob's Message", Shop->welcomeMessage("Bob's Message"));
    ExpectEq("Bob's Message", Shop->welcomeMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ShopTypeSetsAndGetsShopType()
{
    ExpectEq("unknown", Shop->shopType());
    ExpectEq("weapons", Shop->shopType("weapons"));
    ExpectEq("weapons", Shop->shopType());
}

/////////////////////////////////////////////////////////////////////////////
void ShopSubTypeSetsAndGetsShopSubType()
{
    ExpectEq("all", Shop->shopSubType());
    ExpectEq("swords", Shop->shopSubType("swords"));
    ExpectEq("swords", Shop->shopSubType());
}

/////////////////////////////////////////////////////////////////////////////
void Generate15RandomItemsByDefault()
{
    ExpectEq(15, Shop->randomItemsToGenerate());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetAndGetRandomItemsToGenerate()
{
    ExpectEq(15, Shop->randomItemsToGenerate());
    Shop->setRandomItemsToGenerate(9);
    ExpectEq(9, Shop->randomItemsToGenerate());
}

/////////////////////////////////////////////////////////////////////////////
void StoreItemPlacesItemInShopInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectEq(0, sizeof(Shop->storeInventory()));
    ExpectTrue(Shop->storeItem(sword));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    destruct(sword);

    // Verify that the sword data is correct.
    sword = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("all", Shop->storeInventory()["lib/instances/items/weapons/swords/long-sword"]["data"]);
    ExpectEq("Long sword", sword->query("name"));
    ExpectEq("galvorn", sword->query("material"));
    ExpectEq(80, sword->query("craftsmanship"));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void BuyItemRemovesItemFromInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectTrue(Shop->storeItem(sword));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    ExpectTrue(Shop->buyItem("lib/instances/items/weapons/swords/long-sword"));
    ExpectEq(0, sizeof(Shop->storeInventory()));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void BuyItemWithQuantityRemovesItemWhenQuantityBecomesZero()
{
    object potion = load_object("/lib/instances/items/potions/healing.c");
    potion->set("quantity", 2);

    ExpectEq(0, sizeof(Shop->storeInventory()));

    ExpectTrue(Shop->storeItem(potion));
    ExpectEq(1, sizeof(Shop->storeInventory()));

    ExpectTrue(Shop->buyItem("lib/instances/items/potions/healing.c"));
    ExpectEq(1, sizeof(Shop->storeInventory()));

    ExpectTrue(Shop->buyItem("lib/instances/items/potions/healing.c"));
    ExpectEq(0, sizeof(Shop->storeInventory()));

    destruct(potion);
}

/////////////////////////////////////////////////////////////////////////////
void BuyItemDoesNotRemovePermanentItemsFromInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectTrue(Shop->storeItem(sword,1));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    ExpectTrue(Shop->buyItem("lib/instances/items/weapons/swords/long-sword"));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void BuyNonExistantItemReturnsFalseAndDoesNotRemoveItemsFromInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectTrue(Shop->storeItem(sword));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    ExpectFalse(Shop->buyItem("lib/instances/items/weapons/swords/weasel"));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void ResetInventoryClearsInventory()
{
    object sword = load_object("/lib/instances/items/weapons/swords/long-sword.c");
    sword->set("craftsmanship", 80);
    sword->set("material", "galvorn");
    sword->set("bonus attack", 5);

    ExpectTrue(Shop->storeItem(sword));
    ExpectEq(1, sizeof(Shop->storeInventory()));
    Shop->resetInventory();
    ExpectEq(0, sizeof(Shop->storeInventory()));
    destruct(sword);
}

/////////////////////////////////////////////////////////////////////////////
void InitiateShopInteractionShowsShopMenu()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");

    Shop->initiateShopInteraction(player);
    ExpectEq("\x1b[0;36mShop - \x1b[0m\x1b[0;37;1mWelcome\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mPurchase Items      \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSell Items          \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mExit Shop Menu      \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        player->caughtMessage());
    destruct(player);
}

/////////////////////////////////////////////////////////////////////////////
void UpdateShopInventoryRemovesGenericWeaponsButNotSpecialOnes()
{
    object swordA = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    swordA->set("craftsmanship", 80);
    swordA->set("material", "galvorn");
    swordA->set("bonus attack", 5);

    object swordB = clone_object("/lib/instances/items/weapons/swords/long-sword.c");
    Shop->shopType("weapons");

    ExpectTrue(Shop->storeItem(swordA));
    ExpectTrue(Shop->storeItem(swordB));

    mapping inventory = Shop->storeInventory();

    ExpectTrue(member(inventory, object_name(swordA)));
    ExpectTrue(member(inventory, object_name(swordB)));

    Shop->updateShopInventory();
    inventory = Shop->storeInventory();

    ExpectTrue(member(inventory, object_name(swordA)));
    ExpectFalse(member(inventory, object_name(swordB)));
    destruct(swordA);
    destruct(swordB);
}

/////////////////////////////////////////////////////////////////////////////
void UpdateShopInventoryAddsEquipment()
{
    Shop->shopType("weapons");
    Shop->shopSubType("swords");

    ExpectEq(0, sizeof(Shop->storeInventory()));
    Shop->updateShopInventory();
    ExpectTrue(15 < sizeof(Shop->storeInventory()));
}

/////////////////////////////////////////////////////////////////////////////
void CanUpdateNonEquipmentShops()
{
    Shop->shopType("potions");

    ExpectEq(0, sizeof(Shop->storeInventory()));
    ExpectTrue(Shop->shopSellsConsumables());
    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Shop);

    string currentInventory = sprintf("%O\n", Shop->storeInventory());
    ExpectTrue(2 < sizeof(Shop->storeInventory()), "initial size");

    Shop->updateShopInventory();
    ExpectTrue(2 <= sizeof(Shop->storeInventory()), "update called");
    ExpectNotEq(currentInventory, sprintf("%O\n", Shop->storeInventory()));
}

/////////////////////////////////////////////////////////////////////////////
void CanGenerateEquipmentForCustomShops()
{
    Shop->shopType("weapons");
    Shop->shopSubType("staffs");
    Shop->addInventoryItem("unknown", "all", ({
        "/lib/tests/support/items/testSword.c", }));

    ExpectEq(0, sizeof(Shop->storeInventory()));
    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Shop);

    ExpectEq(15, sizeof(Shop->storeInventory()), "initial size");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddCustomItemsToShops()
{
    Shop->shopType("unknown");
    Shop->shopSubType("all");
    Shop->addItem("/lib/tests/support/items/testSword.c");

    ExpectEq(0, sizeof(Shop->storeInventory()));
    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Shop);

    ExpectEq(1, sizeof(Shop->storeInventory()), "initial size");
}

/////////////////////////////////////////////////////////////////////////////
void CustomItemsUpdateCorrectly()
{
    Shop->shopType("unknown");
    Shop->shopSubType("all");
    Shop->addItem("lib/tests/support/items/testSword.c");

    ExpectEq(0, sizeof(Shop->storeInventory()));

    load_object("/lib/dictionaries/shopDictionary.c")->generateInventory(Shop);
    Shop->updateCustomItems();
    ExpectEq(1, sizeof(Shop->storeInventory()), "initial size");

    string itemToGet = m_indices(Shop->storeInventory())[0];
    Shop->buyItem(itemToGet);
    ExpectEq(0, sizeof(Shop->storeInventory()), "bought item");

    Shop->updateCustomItems();
    ExpectEq(1, sizeof(Shop->storeInventory()), "update called");
}
