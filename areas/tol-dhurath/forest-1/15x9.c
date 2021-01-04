//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/montmorency-cherry-stand.c", "northwest");
    addFeature("/lib/environment/features/water/canyon-stream.c", "west");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-1/14x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-1/16x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
