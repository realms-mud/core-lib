//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-creek.c", "northeast");
    addFeature("/lib/environment/features/landforms/mound.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-2/3x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-2/2x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
