//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "east");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "west");

    addExit("west", "/areas/tol-dhurath/temple-exterior/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/temple-exterior/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
