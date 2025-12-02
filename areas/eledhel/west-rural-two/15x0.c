//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cortland-apple-stand.c", "southwest");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "southwest");
    addFeature("/lib/environment/features/landforms/hill.c", "southwest");

    addExit("west", "/areas/eledhel/west-rural-two/14x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/15x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
