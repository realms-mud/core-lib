//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-creek.c", "north");
    addFeature("/lib/environment/features/landforms/butte.c", "east");

    addExit("south", "/areas/tol-dhurath/entry/11x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/entry/10x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
