//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/limestone-interior-shop.c");
    setShortDescription("A well-ordered armory where guards and travelers "
        "inspect fitted armor.");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/military/weapon-rack.c", "east");
    addShop("/lib/environment/shopInventories/armorer.c");
    addObject("/areas/eledhel/central-city/characters/old-city-armorer.c");
    addObject("/areas/eledhel/central-city/characters/armor-customer.c");
    addExit("east", "/areas/eledhel/central-city/old-city-armorer/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/17x1.c",
        "/lib/environment/doors/plank-door.c");
}
