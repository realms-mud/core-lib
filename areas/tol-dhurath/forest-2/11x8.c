//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/butte.c", "northeast");
    addFeature("/lib/environment/features/landforms/hummock.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-2/12x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-2/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
