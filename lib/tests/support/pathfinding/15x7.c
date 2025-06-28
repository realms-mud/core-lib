//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "southeast");
    addFeature("/lib/environment/features/landforms/butte.c", "southeast");
    addFeature("/lib/environment/features/landforms/knoll.c", "southeast");

    addExit("north", "/lib/tests/support/pathfinding/15x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/15x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"keeper of the night","gopher","fisher","gray fox","badger"}));
}

