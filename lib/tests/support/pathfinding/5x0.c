//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northwest");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "northwest");

    addExit("west", "/lib/tests/support/pathfinding/4x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/lib/tests/support/pathfinding/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

