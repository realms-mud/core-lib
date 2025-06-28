//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "east");

    addExit("north", "/lib/tests/support/pathfinding/6x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/lib/tests/support/pathfinding/7x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

