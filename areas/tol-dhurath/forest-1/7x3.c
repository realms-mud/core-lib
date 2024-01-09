//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "southwest");
    addFeature("/lib/environment/features/landforms/tor.c", "southeast");
    addFeature("/lib/environment/features/water/canyon-creek.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-1/7x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/7x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
