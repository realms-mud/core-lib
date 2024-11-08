//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("west", "/areas/tol-dhurath/forest-1/17x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-1/18x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
