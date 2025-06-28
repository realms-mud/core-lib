//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-brook.c", "north");

    addExit("east", "/lib/tests/support/pathfinding/19x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/17x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/lib/tests/support/pathfinding/18x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

