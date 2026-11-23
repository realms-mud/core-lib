//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/brick-interior-shop.c");
    addItem("/lib/environment/items/furniture/chest.c", "north");
    addItem("/lib/environment/items/furniture/workbench.c", "east");
    addObject("/areas/eledhel/southern-city/characters/warehouse-clerk.c");

    addExitWithDoor("west", "/areas/eledhel/southern-city/19x6.c",
        "/lib/environment/doors/plank-door.c");
    addExit("south", "/areas/eledhel/southern-city/warehouse/1x0.c");
}
