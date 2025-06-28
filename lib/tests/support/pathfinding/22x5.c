//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/hill.c", "southeast");
    addFeature("/lib/environment/features/water/canyon-creek.c", "southeast");

    addExit("east", "/lib/tests/support/pathfinding/23x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/22x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

