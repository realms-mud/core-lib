//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "northwest");

    addExit("west", "/lib/tests/support/pathfinding/6x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/lib/tests/support/pathfinding/8x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

