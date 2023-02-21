//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-stream.c", "south");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "northwest");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-2/17x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-2/17x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-2/16x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
