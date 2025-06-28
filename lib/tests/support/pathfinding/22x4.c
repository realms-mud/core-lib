//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/holly-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/bluff.c", "southeast");

    addExit("east", "/lib/tests/support/pathfinding/23x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/lib/tests/support/pathfinding/22x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"gray fox","skunk","outlaw","gray squirrel"}));
}

