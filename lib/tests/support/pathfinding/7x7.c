//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "southwest");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "southwest");

    addExit("west", "/lib/tests/support/pathfinding/6x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"groundhog","hunter","coyote","porcupine","knight of the storm","raccoon"}));
}

