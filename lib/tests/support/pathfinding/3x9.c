//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "north");

    addExit("west", "/lib/tests/support/pathfinding/2x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/lib/tests/support/pathfinding/3x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

