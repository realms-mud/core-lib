//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "north");
    addFeature("/lib/environment/features/water/lake-shore-bluff.c", "south");
    addFeature("/lib/environment/features/water/gulley-creek.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-1/11x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/11x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-1/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
