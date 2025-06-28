//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/valley.c", "southwest");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "southwest");
    addFeature("/lib/environment/features/water/creek.c", "southwest");

    addExit("south", "/lib/tests/support/pathfinding/20x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/lib/tests/support/pathfinding/19x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

