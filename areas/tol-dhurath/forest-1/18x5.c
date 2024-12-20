//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/valley.c", "west");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-1/17x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-1/18x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
