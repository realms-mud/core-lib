//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("A saddler's shop filled with harnesses, bridles, "
        "and travel-worn leather goods.");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/small-shelf.c", "east");
    addShop("/lib/environment/shopInventories/medium-armorer.c");
    addObject("/areas/eledhel/central-city/characters/old-city-saddler.c");
    addObject("/areas/eledhel/central-city/characters/saddlery-customer.c");
    addExit("east", "/areas/eledhel/central-city/old-city-saddlery/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/17x0.c",
        "/lib/environment/doors/plank-door.c");
}
