//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    addItem("/lib/environment/items/lighting/forge-fire.c", "east");
    addItem("/lib/environment/items/furniture/workbench.c", "north");
    addObject("/areas/eledhel/southern-city/characters/smelter.c");

    addExitWithDoor("west", "/areas/eledhel/southern-city/14x6.c",
        "/lib/environment/doors/plank-door.c");
    addExit("south", "/areas/eledhel/southern-city/smelter/1x0.c");
}
