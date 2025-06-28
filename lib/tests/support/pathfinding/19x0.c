//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-creek.c", "east");

    addExit("west", "/lib/tests/support/pathfinding/18x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"boar","black bear","red fox","mink","outlaw","porcupine"}));
}

