//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "south");
    addFeature("/lib/environment/features/landforms/bluff.c", "south");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "south");

    addExit("south", "/lib/tests/support/pathfinding/17x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/lib/tests/support/pathfinding/18x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

