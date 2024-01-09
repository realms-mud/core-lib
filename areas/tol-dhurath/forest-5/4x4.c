//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "south");
    addFeature("/lib/environment/features/water/ravine-creek.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("east", "/areas/tol-dhurath/forest-5/5x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-5/4x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
