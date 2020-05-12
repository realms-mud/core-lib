//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/holly-stand.c", "west");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/entry/15x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/entry/15x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
