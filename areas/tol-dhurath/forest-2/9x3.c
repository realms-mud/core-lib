//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "east");
    addFeature("/lib/environment/features/trees/birch-stand.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-2/8x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-2/9x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"gray fox","ruffian","mule deer"}));
}
