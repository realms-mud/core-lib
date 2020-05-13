//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-2/11x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/12x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
