//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "south");
    addFeature("/lib/environment/features/water/canyon-stream.c", "west");
    addFeature("/lib/environment/features/trees/ash-stand.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-3/2x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-3/4x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
