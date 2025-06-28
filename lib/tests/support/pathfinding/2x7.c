//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "south");
    addFeature("/lib/environment/features/landforms/hillock.c", "south");

    addExit("east", "/lib/tests/support/pathfinding/3x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/2x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/2x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

