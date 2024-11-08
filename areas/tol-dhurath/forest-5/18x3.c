//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-5/19x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-5/18x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
