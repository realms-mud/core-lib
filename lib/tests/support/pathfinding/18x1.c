//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "southwest");

    addExit("west", "/lib/tests/support/pathfinding/17x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/lib/tests/support/pathfinding/19x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/18x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

