//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "north");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-2/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/7x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
