//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");
    addFeature("/lib/environment/features/water/brook.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-1/0x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-1/1x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
