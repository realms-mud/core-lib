//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "east");
    addItem("/lib/environment/items/objects/boundary-stone.c", "west");

    addDecorator("village north-south road");

    addExit("north", "/areas/northern-road/north-gate/0x2.c");
    addExit("south", "/areas/northern-road/north-gate/0x4.c");
}
