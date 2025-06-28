//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "northwest");

    addExit("east", "/lib/tests/support/pathfinding/7x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/5x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/lib/tests/support/pathfinding/6x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

