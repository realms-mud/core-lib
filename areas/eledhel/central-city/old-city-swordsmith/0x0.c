//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/limestone-interior-shop.c");
    setShortDescription("A swordsmith's sales floor, bright with polished "
        "steel and crowded with waiting customers.");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/military/weapon-rack.c", "east");
    addShop("/lib/environment/shopInventories/swordsmith.c");
    addObject("/areas/eledhel/central-city/characters/old-city-swordsmith.c");
    addObject("/areas/eledhel/central-city/characters/sword-commissioner.c");
    addExit("east", "/areas/eledhel/central-city/old-city-swordsmith/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/17x0.c",
        "/lib/environment/doors/plank-door.c");
}
