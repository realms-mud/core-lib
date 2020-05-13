//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "west");
    addFeature("/lib/environment/features/water/canyon-stream.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-2/2x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-2/1x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
