//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/yew-stand.c", "southwest");
    addFeature("/lib/environment/features/water/gulley-creek.c", "southwest");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southwest");

    addExit("east", "/areas/tol-dhurath/forest-5/18x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-5/17x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
