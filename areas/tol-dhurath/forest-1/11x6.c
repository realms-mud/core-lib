//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "north");
    addFeature("/lib/environment/features/water/canyon-brook.c", "east");
    addFeature("/lib/environment/features/landforms/glen.c", "southwest");

    addExit("south", "/areas/tol-dhurath/forest-1/11x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/11x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
