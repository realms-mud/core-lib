//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "east");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "east");
    addFeature("/lib/environment/features/water/gulley-creek.c", "east");

    addExit("south", "/lib/tests/support/pathfinding/11x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/lib/tests/support/pathfinding/10x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

