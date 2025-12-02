//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "west");
    addFeature("/lib/environment/features/water/ravine-brook.c", "east");
    addFeature("/lib/environment/features/water/gulley-creek.c", "southwest");

    addExit("east", "/areas/tol-dhurath/temple-exterior/7x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/temple-exterior/5x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
