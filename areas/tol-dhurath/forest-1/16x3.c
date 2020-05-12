//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hill.c", "southwest");
    addFeature("/lib/environment/features/landforms/valley.c", "southwest");

    addExit("north", "/areas/tol-dhurath/forest-1/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-1/16x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
