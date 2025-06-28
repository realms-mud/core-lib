//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("west", "/lib/tests/support/pathfinding/17x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/lib/tests/support/pathfinding/18x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

