//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pear-stand.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "south");
    addFeature("/lib/environment/features/landforms/combe.c", "south");

    addExit("south", "/lib/tests/support/pathfinding/12x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/lib/tests/support/pathfinding/11x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"mountain lion","hunter","ruffian","mule deer","outlaw","chipmunk"}));
}

