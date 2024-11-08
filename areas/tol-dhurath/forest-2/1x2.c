//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-2/0x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-2/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
