//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/waterfall.c", "east");

    addExit("west", "/areas/tol-dhurath/entry/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/entry/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/entry/23x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
