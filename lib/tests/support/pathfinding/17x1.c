//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("west", "/lib/tests/support/pathfinding/16x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/lib/tests/support/pathfinding/18x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}

