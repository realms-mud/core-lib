//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "southwest");
    addFeature("/lib/environment/features/trees/black-locust-stand.c", "southwest");

    addExit("west", "/areas/tol-dhurath/forest-5/0x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-5/2x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
