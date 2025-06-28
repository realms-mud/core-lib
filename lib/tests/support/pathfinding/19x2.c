//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "north");

    addExit("east", "/lib/tests/support/pathfinding/20x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/19x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/19x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"groundhog","keeper of the night","knight of the storm"}));
}

