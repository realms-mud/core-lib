//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");
    addFeature("/lib/environment/features/trees/cortland-apple-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-3/16x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-3/15x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
