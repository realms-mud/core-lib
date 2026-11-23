//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The southern shipyard's repair floor");
    addItem("/lib/environment/items/furniture/workbench.c", "north");
    addItem("/lib/environment/items/furniture/small-shelf.c", "east");
    addObject("/areas/eledhel/southern-city/characters/shipwright.c");

    addExit("east", "/areas/eledhel/southern-city/shipyard/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/southern-city/21x7.c",
        "/lib/environment/doors/plank-door.c");
}
