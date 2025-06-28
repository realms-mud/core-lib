//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "northeast");
    addFeature("/lib/environment/features/landforms/ridge.c", "northeast");

    addExit("south", "/lib/tests/support/pathfinding/14x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/14x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"moose","gray wolf","mink"}));
}

