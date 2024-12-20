//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "southeast");
    addFeature("/lib/environment/features/water/ravine-creek.c", "southeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southeast");

    addExit("east", "/areas/tol-dhurath/forest-5/7x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-5/5x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
