//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("The furrier's shop, lined with winter cloaks "
        "and carefully brushed pelts.");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/mirror.c", "east");
    addShop("/lib/environment/shopInventories/tailor.c");
    addObject("/areas/eledhel/central-city/characters/furrier.c");
    addObject("/areas/eledhel/central-city/characters/furrier-customer.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/12x0.c",
        "/lib/environment/doors/plank-door.c");
    addExit("east", "/areas/eledhel/central-city/furrier/1x0.c");
}
