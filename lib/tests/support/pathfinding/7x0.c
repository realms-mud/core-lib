//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "southwest");

    addExit("east", "/lib/tests/support/pathfinding/8x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/6x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"mountain lion","coyote","outlaw","timber wolf","knight of the storm"}));
}

