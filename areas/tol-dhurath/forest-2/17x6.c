//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-creek.c", "north");
    addFeature("/lib/environment/features/landforms/hill.c", "southeast");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("south", "/areas/tol-dhurath/forest-2/17x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-2/17x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-2/18x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
