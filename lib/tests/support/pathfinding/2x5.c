//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "northeast");
    addFeature("/lib/environment/features/landforms/glen.c", "northeast");
    addFeature("/lib/environment/features/water/ravine-brook.c", "northeast");

    addExit("north", "/lib/tests/support/pathfinding/2x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/lib/tests/support/pathfinding/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

