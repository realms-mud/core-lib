//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/kingwood-stand.c", "east");
    addFeature("/lib/environment/features/water/creek.c", "west");

    addExit("west", "/areas/tol-dhurath/temple-exterior/17x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/temple-exterior/18x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
