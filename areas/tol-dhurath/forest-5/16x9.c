//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southwest");
    addFeature("/lib/environment/features/water/gulley-creek.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");

    addExit("east", "/areas/tol-dhurath/forest-5/17x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-5/15x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
