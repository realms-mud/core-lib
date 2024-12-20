//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/water/canyon-creek.c", "southwest");

    addExit("west", "/areas/tol-dhurath/forest-4/23x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-4/24x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"warg","opossum","raccoon","chipmunk"}));
}
