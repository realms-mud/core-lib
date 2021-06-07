//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "south");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "south");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");

    addExit("east", "/areas/tol-dhurath/forest-5/9x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-5/7x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
