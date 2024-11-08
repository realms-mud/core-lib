//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-2/1x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/2x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
