//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "southeast");
    addFeature("/lib/environment/features/trees/chokecherry-stand.c", "southeast");

    addExit("north", "/lib/tests/support/pathfinding/3x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/lib/tests/support/pathfinding/2x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

