//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/mound.c", "southeast");
    addFeature("/lib/environment/features/water/brook.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-2/9x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
