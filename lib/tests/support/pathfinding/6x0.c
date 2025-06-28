//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "east");
    addFeature("/lib/environment/features/landforms/hill.c", "east");

    addExit("east", "/lib/tests/support/pathfinding/7x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/lib/tests/support/pathfinding/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

