//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/waterfall.c", "north");
    addFeature("/lib/environment/features/trees/bing-cherry-stand.c", "west");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "east");

    addExit("south", "/areas/tol-dhurath/entry/0x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/entry/0x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
