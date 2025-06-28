//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "southwest");

    addExit("east", "/lib/tests/support/pathfinding/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/0x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

