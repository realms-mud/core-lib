//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    addItem("/lib/environment/items/lighting/fireplace.c", "north");
    addItem("/lib/environment/items/furniture/trestle-table.c", "none");
    addItem("/lib/environment/items/furniture/bench.c", "east");
    addItem("/lib/environment/items/objects/notice-board.c", "south");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "west");
    addObject("/areas/eledhel/central-rural/characters/rethan/rethan.c");

    addExit("north", "/areas/eledhel/central-rural/common-measure/0x0.c");
    addExit("east", "/areas/eledhel/central-rural/common-measure/1x1.c");
    addExitWithDoor("west", "/areas/eledhel/central-rural/24x6.c",
        "/lib/environment/doors/plank-door.c");
}
