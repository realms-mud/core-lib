//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "southeast");
    addFeature("/lib/environment/features/water/ravine-brook.c", "southeast");

    addExit("east", "/areas/tol-dhurath/forest-5/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-5/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
