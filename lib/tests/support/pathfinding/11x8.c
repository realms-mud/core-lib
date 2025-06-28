//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/promontory.c", "southwest");
    addFeature("/lib/environment/features/trees/beech-stand.c", "southwest");

    addExit("east", "/lib/tests/support/pathfinding/12x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

