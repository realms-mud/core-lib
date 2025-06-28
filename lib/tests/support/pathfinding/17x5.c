//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "north");
    addFeature("/lib/environment/features/trees/birch-stand.c", "north");
    addFeature("/lib/environment/features/landforms/tor.c", "north");

    addExit("east", "/lib/tests/support/pathfinding/18x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/lib/tests/support/pathfinding/17x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

