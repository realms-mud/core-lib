//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("The shipyard's dockside office");
    addItem("/lib/environment/items/furniture/desk.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "east");
    addObject(
        "/areas/eledhel/southern-city/characters/shipyard-apprentice.c");

    addExit("west", "/areas/eledhel/southern-city/shipyard/0x0.c");
    addExit("north", "/areas/eledhel/southern-city/shipyard/1x1.c");
    addExitWithDoor("south", "/areas/eledhel/southern-city/22x4.c",
        "/lib/environment/doors/plank-door.c");
}
