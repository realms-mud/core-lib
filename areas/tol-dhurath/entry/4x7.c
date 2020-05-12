//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/lake-shore-bluff.c", "south");
    addFeature("/lib/environment/features/trees/willow-stand.c", "south");

    addExit("east", "/areas/tol-dhurath/entry/5x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/entry/4x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
