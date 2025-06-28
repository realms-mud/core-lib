//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gorge-creek.c", "west");
    addFeature("/lib/environment/features/landforms/dell.c", "west");

    addExit("south", "/lib/tests/support/pathfinding/9x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/lib/tests/support/pathfinding/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

