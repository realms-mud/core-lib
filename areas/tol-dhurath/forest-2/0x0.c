//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southeast");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "southeast");
    addFeature("/lib/environment/features/landforms/butte.c", "southeast");

    addExit("east", "/areas/tol-dhurath/forest-2/1x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
