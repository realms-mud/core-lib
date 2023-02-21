//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "southwest");
    addFeature("/lib/environment/features/water/canyon-brook.c", "east");
    addFeature("/lib/environment/features/trees/ash-stand.c", "north");

    addExit("south", "/areas/tol-dhurath/entry/0x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/entry/0x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
