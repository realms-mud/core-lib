//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/brick-interior-shop.c");
    addShop("/lib/environment/shopInventories/provisions.c");
    addItem("/lib/environment/items/furniture/table.c", "north");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addObject("/areas/eledhel/southern-city/characters/market-merchant.c");
    addObject("/areas/eledhel/southern-city/characters/market-customer.c");

    addExitWithDoor("west", "/areas/eledhel/southern-city/19x5.c",
        "/lib/environment/doors/plank-door.c");
    addExit("east", "/areas/eledhel/southern-city/market/1x0.c");
}
