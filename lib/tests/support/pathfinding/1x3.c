//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "northeast");
    addFeature("/lib/environment/features/water/waterfall.c", "northeast");

    addExit("west", "/lib/tests/support/pathfinding/0x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/lib/tests/support/pathfinding/1x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/1x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

