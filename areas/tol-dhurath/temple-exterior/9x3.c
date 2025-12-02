//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/birch-stand.c", "north");

    addExit("north", "/areas/tol-dhurath/temple-exterior/9x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/temple-exterior/8x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
