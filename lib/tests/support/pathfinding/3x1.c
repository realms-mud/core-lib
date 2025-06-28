//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southwest");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/mound.c", "southwest");

    addExit("east", "/lib/tests/support/pathfinding/4x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/3x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

