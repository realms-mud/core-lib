//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "southwest");

    addExit("east", "/areas/tol-dhurath/forest-1/17x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-1/15x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
