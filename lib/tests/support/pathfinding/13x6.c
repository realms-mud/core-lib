//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "east");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "east");

    addExit("north", "/lib/tests/support/pathfinding/13x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/lib/tests/support/pathfinding/12x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

