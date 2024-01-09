//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "northwest");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "east");

    addExit("west", "/areas/tol-dhurath/forest-1/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-1/3x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
