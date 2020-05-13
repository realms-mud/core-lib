//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-creek.c", "west");
    addFeature("/lib/environment/features/water/creek.c", "east");
    addFeature("/lib/environment/features/landforms/hollow.c", "southwest");

    addExit("east", "/areas/tol-dhurath/temple-exterior/4x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/temple-exterior/3x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
