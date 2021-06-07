//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "north");
    addFeature("/lib/environment/features/water/gorge-creek.c", "north");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-4/14x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-4/13x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
