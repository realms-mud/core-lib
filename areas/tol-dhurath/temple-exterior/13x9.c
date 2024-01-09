//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "southwest");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addFeature("/lib/environment/features/water/waterfall.c", "east");

    addExit("south", "/areas/tol-dhurath/temple-exterior/13x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/temple-exterior/14x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
