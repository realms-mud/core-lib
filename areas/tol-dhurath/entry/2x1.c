//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/montmorency-cherry-stand.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");

    addExit("east", "/areas/tol-dhurath/entry/3x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/entry/1x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
