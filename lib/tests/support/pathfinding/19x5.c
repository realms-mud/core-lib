//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "north");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");
    addFeature("/lib/environment/features/water/stream.c", "north");

    addExit("north", "/lib/tests/support/pathfinding/19x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/lib/tests/support/pathfinding/18x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"groundhog","ruffian","skeleton"}));
}

