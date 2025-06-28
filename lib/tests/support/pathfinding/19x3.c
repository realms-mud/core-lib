//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/precipice.c", "northwest");
    addFeature("/lib/environment/features/landforms/hummock.c", "northwest");
    addFeature("/lib/environment/features/trees/crabapple-stand.c", "northwest");

    addExit("west", "/lib/tests/support/pathfinding/18x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/lib/tests/support/pathfinding/19x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/19x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

