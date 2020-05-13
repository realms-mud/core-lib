//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/buckeye-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");

    addExit("north", "/areas/tol-dhurath/entry/1x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/entry/0x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
