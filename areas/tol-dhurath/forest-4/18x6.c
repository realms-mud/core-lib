//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/promontory.c", "southwest");
    addFeature("/lib/environment/features/water/gorge-creek.c", "southwest");

    addExit("north", "/areas/tol-dhurath/forest-4/18x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-4/18x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
