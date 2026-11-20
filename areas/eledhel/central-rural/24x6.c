//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addDecorator("farm track intersection");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addItem("/lib/environment/items/objects/common-measure-sign.c", "north");
    addItem("/lib/environment/items/objects/notice-board.c", "southwest");
    addBuildingWithDoor("/lib/environment/buildings/homes/wooden-house.c",
        "east",
        "/areas/eledhel/central-rural/common-measure/0x1.c",
        "/lib/environment/doors/plank-door.c");

    addExit("west", "/areas/eledhel/central-rural/23x6.c");
    addExit("south", "/areas/eledhel/central-rural/24x5.c");
    addExit("north", "/areas/eledhel/central-rural/24x7.c");
}
