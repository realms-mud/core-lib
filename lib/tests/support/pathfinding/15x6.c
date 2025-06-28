//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hollow.c", "southeast");

    addExit("north", "/lib/tests/support/pathfinding/15x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}

