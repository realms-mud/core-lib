//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "east");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "west");
    addFeature("/lib/environment/features/landforms/ridge.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-2/3x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-2/4x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
