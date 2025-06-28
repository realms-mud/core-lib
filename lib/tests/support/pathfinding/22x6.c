//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "east");
    addFeature("/lib/environment/features/landforms/glen.c", "east");

    addExit("south", "/lib/tests/support/pathfinding/22x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/lib/tests/support/pathfinding/21x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"mule deer","ruffian","muskrat"}));
}

