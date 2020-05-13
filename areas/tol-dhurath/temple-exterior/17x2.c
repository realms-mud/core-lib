//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "south");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "west");

    addExit("north", "/areas/tol-dhurath/temple-exterior/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/temple-exterior/16x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
