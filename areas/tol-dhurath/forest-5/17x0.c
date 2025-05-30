//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "east");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-5/18x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-5/16x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
