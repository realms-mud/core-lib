//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "east");
    addFeature("/lib/environment/features/landforms/hill.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-1/7x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-1/8x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
