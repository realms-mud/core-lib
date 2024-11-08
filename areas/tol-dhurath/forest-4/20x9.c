//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-4/20x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-4/19x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
