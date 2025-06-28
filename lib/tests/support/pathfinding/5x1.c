//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addFeature("/lib/environment/features/water/creek.c", "east");

    addExit("east", "/lib/tests/support/pathfinding/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/4x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/lib/tests/support/pathfinding/5x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/5x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

