//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "south");
    addFeature("/lib/environment/features/trees/elm-stand.c", "south");
    addFeature("/lib/environment/features/landforms/butte.c", "south");

    addExit("east", "/lib/tests/support/pathfinding/20x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/18x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/lib/tests/support/pathfinding/19x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

