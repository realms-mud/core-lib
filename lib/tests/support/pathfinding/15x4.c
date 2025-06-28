//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cedar-stand.c", "northeast");
    addFeature("/lib/environment/features/landforms/butte.c", "northeast");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northeast");

    addExit("east", "/lib/tests/support/pathfinding/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/lib/tests/support/pathfinding/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

