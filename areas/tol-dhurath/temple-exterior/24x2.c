//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "west");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "southwest");

    addExit("south", "/areas/tol-dhurath/temple-exterior/24x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/temple-exterior/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
