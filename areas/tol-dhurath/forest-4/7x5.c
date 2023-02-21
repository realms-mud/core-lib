//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "west");
    addFeature("/lib/environment/features/water/canyon-brook.c", "west");
    addFeature("/lib/environment/features/water/canyon-stream.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-4/7x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-4/8x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
