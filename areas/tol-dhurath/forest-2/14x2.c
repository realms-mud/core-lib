//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-creek.c", "north");
    addFeature("/lib/environment/features/landforms/hollow.c", "southeast");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("east", "/areas/tol-dhurath/forest-2/15x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/forest-2/14x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
