//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northwest");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "northwest");
    addFeature("/lib/environment/features/water/pond.c", "northwest");

    addExit("west", "/lib/tests/support/pathfinding/14x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/lib/tests/support/pathfinding/15x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/15x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"ruffian","beaver","fisher"}));
}

