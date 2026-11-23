//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("The leatherworker's busy front shop");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/small-shelf.c", "east");
    addShop("/lib/environment/shopInventories/medium-armorer.c");
    addObject(
        "/areas/eledhel/central-city/characters/leatherworker.c");
    addObject(
        "/areas/eledhel/central-city/characters/leather-shopper.c");

    addExit("east", "/areas/eledhel/central-city/leather-merchant/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/14x0.c",
        "/lib/environment/doors/plank-door.c");
}
