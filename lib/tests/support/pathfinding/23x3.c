//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "south");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "south");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");

    addExit("east", "/lib/tests/support/pathfinding/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

