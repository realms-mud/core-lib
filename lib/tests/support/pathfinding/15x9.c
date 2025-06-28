//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/hummock.c", "southwest");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "southwest");

    addExit("east", "/lib/tests/support/pathfinding/16x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/15x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

