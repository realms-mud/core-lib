//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("north", "/areas/tol-dhurath/entry/12x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/entry/12x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
