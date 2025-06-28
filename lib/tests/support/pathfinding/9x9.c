//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "west");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "west");

    addExit("east", "/lib/tests/support/pathfinding/10x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/8x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

