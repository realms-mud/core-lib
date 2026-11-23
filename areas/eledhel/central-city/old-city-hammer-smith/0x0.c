//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/limestone-interior-shop.c");
    setShortDescription("A hammer-smith's shop for tools, fittings, and "
        "heavy work.");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/lighting/forge-fire.c", "east");
    addShop("/lib/environment/shopInventories/hammer-smith.c");
    addObject(
        "/areas/eledhel/central-city/characters/old-city-hammer-smith.c");
    addObject("/areas/eledhel/central-city/characters/hammer-customer.c");
    addExit("east",
        "/areas/eledhel/central-city/old-city-hammer-smith/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/20x1.c",
        "/lib/environment/doors/plank-door.c");
}
