//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/shopInventories/baseShop.c";

private mapping produce = ([
    "/lib/instances/items/food/plants/fruit/apple.c":2,
    "/lib/instances/items/food/plants/roots/onion.c":2,
    "/lib/instances/items/food/plants/roots/carrot.c":2,
    "/lib/instances/items/food/plants/roots/turnip.c":2,
    "/lib/instances/items/food/plants/greens/cabbage.c":4
]);

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("The Provision Counter");
    welcomeMessage("Fresh produce and stored roots for the road");
    shopType("food");
}

/////////////////////////////////////////////////////////////////////////////
public void updateCustomItems()
{
    mapping stock = storeInventory();
    foreach (string path, int price in produce)
    {
        if (!member(stock, path))
        {
            object item = clone_object(path);
            item->set("quantity", 6);
            item->set("value", price);
            item->identify();
            if (!storeItem(item))
            {
                raise_error("Unable to stock provisions: " + path + "\n");
            }
            destruct(item);
        }
    }
}
