//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/persimmon-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/entry/10x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/entry/9x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/entry/10x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
