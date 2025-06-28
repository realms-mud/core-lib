//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southwest");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "southwest");
    addFeature("/lib/environment/features/landforms/hill.c", "southwest");

    addExit("south", "/lib/tests/support/pathfinding/6x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/6x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

