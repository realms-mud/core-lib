//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("The common room of a modest inn on the southern "
        "trade street.");
    addItem("/lib/environment/items/furniture/long-table.c", "west");
    addItem("/lib/environment/items/lighting/fireplace.c", "north");
    addShop("/lib/environment/shopInventories/provisions.c");
    addObject("/areas/eledhel/central-city/characters/wayfarer-innkeeper.c");
    addObject("/areas/eledhel/central-city/characters/wayfarer-guest.c");
    addExit("east", "/areas/eledhel/central-city/wayfarer-inn/0x1.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/20x1.c",
        "/lib/environment/doors/plank-door.c");
}
