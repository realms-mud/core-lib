//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "north");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "north");

    addExit("east", "/lib/tests/support/pathfinding/3x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/lib/tests/support/pathfinding/2x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/lib/tests/support/pathfinding/2x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"mule deer","skeleton","zombie","timber wolf","weasel"}));
}

