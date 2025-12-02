//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "south");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-2/16x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-2/15x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
