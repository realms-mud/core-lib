//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/pond.c", "north");
    addFeature("/lib/environment/features/water/creek.c", "north");

    addExit("south", "/lib/tests/support/pathfinding/12x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/12x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

