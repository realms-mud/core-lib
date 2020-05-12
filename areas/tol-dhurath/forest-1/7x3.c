//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "east");
    addFeature("/lib/environment/features/landforms/tor.c", "east");
    addFeature("/lib/environment/features/water/canyon-creek.c", "east");

    addExit("south", "/areas/tol-dhurath/forest-1/7x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/7x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
