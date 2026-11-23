//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("A small brewery keeps a counter of fruit, roots, "
        "and household provisions beside its cider casks.");
    addShop("/lib/environment/shopInventories/provisions.c");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/long-table.c", "east");
    addObject("/areas/eledhel/central-city/characters/brewer.c");
    addObject("/areas/eledhel/central-city/characters/brewery-customer.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/12x1.c",
        "/lib/environment/doors/plank-door.c");
    addExit("south", "/areas/eledhel/central-city/brewery/1x0.c");
}
