//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/mound.c", "south");
    addFeature("/lib/environment/features/trees/maple-stand.c", "south");
    addFeature("/lib/environment/features/trees/birch-stand.c", "south");

    addExit("north", "/lib/tests/support/pathfinding/13x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/lib/tests/support/pathfinding/13x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"hunter","mule deer","keeper of the night","skunk","mink"}));
}

