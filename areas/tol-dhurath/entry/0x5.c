//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/crag.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "northeast");

    addExit("south", "/areas/tol-dhurath/entry/0x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/entry/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/entry/0x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
