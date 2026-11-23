//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("The southern quay's provisions counter");
    addItem("/lib/environment/items/lighting/window.c", "east");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/small-shelf.c", "west");
    addShop("/lib/environment/shopInventories/provisions.c");
    addObject(
        "/areas/eledhel/southern-city/characters/dock-merchant.c");
    addObject(
        "/areas/eledhel/southern-city/characters/dock-market-customer.c");

    addExitWithDoor("south", "/areas/eledhel/southern-city/20x4.c",
        "/lib/environment/doors/plank-door.c");
}
