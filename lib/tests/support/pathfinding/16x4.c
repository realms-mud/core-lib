//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");
    addFeature("/lib/environment/features/trees/rosewood-stand.c", "northeast");
    addFeature("/lib/environment/features/water/gulley-creek.c", "northeast");

    addExit("north", "/lib/tests/support/pathfinding/16x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/lib/tests/support/pathfinding/15x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

