//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northeast");
    addFeature("/lib/environment/features/trees/fir-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/cedar-stand.c", "northeast");

    addExit("east", "/areas/tol-dhurath/entry/9x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/entry/8x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/entry/7x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
