//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "north");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "west");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-3/6x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-3/8x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
