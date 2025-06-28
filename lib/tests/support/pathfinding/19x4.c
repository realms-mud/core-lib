//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "south");
    addFeature("/lib/environment/features/water/gulley-creek.c", "south");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");

    addExit("south", "/lib/tests/support/pathfinding/19x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/lib/tests/support/pathfinding/18x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

