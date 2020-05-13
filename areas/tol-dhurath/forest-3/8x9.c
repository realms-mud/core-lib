//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-3/9x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-3/8x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
