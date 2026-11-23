//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("The tailor's public shop and fitting counter");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/mirror.c", "east");
    addShop("/lib/environment/shopInventories/tailor.c");
    addObject("/areas/eledhel/central-city/characters/tailor.c");
    addObject("/areas/eledhel/central-city/characters/tailor-customer.c");

    addExit("east", "/areas/eledhel/central-city/old-city-tailor/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/14x1.c",
        "/lib/environment/doors/plank-door.c");
}
