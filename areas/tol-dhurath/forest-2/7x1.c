//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-brook.c", "east");
    addFeature("/lib/environment/features/water/ravine-creek.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-2/8x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-2/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
