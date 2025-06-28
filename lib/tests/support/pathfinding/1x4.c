//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gorge-creek.c", "southwest");
    addFeature("/lib/environment/features/trees/nectarine-stand.c", "southwest");

    addExit("north", "/lib/tests/support/pathfinding/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

