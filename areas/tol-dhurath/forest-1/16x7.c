//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "southeast");
    addFeature("/lib/environment/features/water/canyon-stream.c", "southeast");
    addFeature("/lib/environment/features/trees/ironwood-stand.c", "southeast");

    addExit("west", "/areas/tol-dhurath/forest-1/15x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-1/16x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
