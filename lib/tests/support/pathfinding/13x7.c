//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "west");
    addFeature("/lib/environment/features/landforms/butte.c", "west");

    addExit("east", "/lib/tests/support/pathfinding/14x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/13x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/13x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

