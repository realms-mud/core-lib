//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "west");
    addFeature("/lib/environment/features/landforms/hillock.c", "southwest");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "south");

    addExit("east", "/areas/tol-dhurath/forest-1/16x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-1/15x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
