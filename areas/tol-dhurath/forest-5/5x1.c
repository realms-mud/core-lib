//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "south");
    addFeature("/lib/environment/features/trees/rosewood-stand.c", "south");

    addExit("south", "/areas/tol-dhurath/forest-5/5x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-5/5x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-5/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
