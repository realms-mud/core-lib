//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-stream.c", "south");
    addFeature("/lib/environment/features/water/canyon-brook.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("west", "/areas/tol-dhurath/entry/5x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/entry/6x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
