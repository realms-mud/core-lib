//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-brook.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "east");

    addExit("north", "/areas/tol-dhurath/entry/9x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/entry/8x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/entry/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
