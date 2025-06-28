//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/mound.c", "southeast");
    addFeature("/lib/environment/features/water/brook.c", "southeast");

    addExit("south", "/lib/tests/support/pathfinding/10x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/lib/tests/support/pathfinding/9x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","hunter","mink","timber wolf"}));
}

