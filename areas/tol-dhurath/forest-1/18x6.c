//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "north");
    addFeature("/lib/environment/features/water/pond.c", "northwest");
    addFeature("/lib/environment/features/landforms/valley.c", "east");

    addExit("south", "/areas/tol-dhurath/forest-1/18x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-1/17x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
