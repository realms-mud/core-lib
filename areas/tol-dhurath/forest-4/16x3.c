//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "north");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "north");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("north", "/areas/tol-dhurath/forest-4/16x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-4/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
