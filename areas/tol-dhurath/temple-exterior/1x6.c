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
    addFeature("/lib/environment/features/trees/pine-stand.c", "east");

    addExit("north", "/areas/tol-dhurath/temple-exterior/1x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/temple-exterior/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
