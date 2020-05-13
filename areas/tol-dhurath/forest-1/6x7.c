//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "north");
    addFeature("/lib/environment/features/water/waterfall.c", "east");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-1/6x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-1/7x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
