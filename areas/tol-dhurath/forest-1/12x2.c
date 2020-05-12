//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gorge-creek.c", "southwest");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southwest");

    addExit("east", "/areas/tol-dhurath/forest-1/13x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-1/12x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
