//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addFeature("/lib/environment/features/water/canyon-stream.c", "northeast");

    addExit("south", "/areas/tol-dhurath/entry/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/entry/1x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
