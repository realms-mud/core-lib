//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "south");
    addItem("/lib/environment/items/objects/signPost.c", "north");
    addItem("/lib/environment/items/objects/boundary-stone.c", "southwest");

    addDecorator("village road T-south");

    addExit("east", "/areas/eledhel/central-rural/21x3.c");
    addExit("south", "/areas/northern-road/north-gate/3x4.c");
    addExit("west", "/areas/northern-road/north-gate/2x3.c");
}
