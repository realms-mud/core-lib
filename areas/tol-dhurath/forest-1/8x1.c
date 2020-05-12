//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "east");
    addFeature("/lib/environment/features/water/canyon-creek.c", "east");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-1/9x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-1/8x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
