//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "south");
    addFeature("/lib/environment/features/water/gulley-creek.c", "south");
    addFeature("/lib/environment/features/landforms/combe.c", "south");

    addExit("north", "/areas/tol-dhurath/forest-4/19x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-4/20x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
