//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    setShortDescription("A neighborhood tavern serves warm meals to "
        "workers returning from Gate Street.");
    addShop("/lib/environment/shopInventories/provisions.c");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/lighting/hearth.c", "east");
    addObject("/areas/eledhel/central-city/characters/tavernkeeper.c");
    addObject("/areas/eledhel/central-city/characters/tavern-guest.c");
    addExitWithDoor("east", "/areas/eledhel/central-city/12x0.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/central-city/tavern/1x0.c");
}
