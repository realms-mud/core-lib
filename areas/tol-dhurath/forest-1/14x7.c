//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "west");
    addFeature("/lib/environment/features/water/ravine-brook.c", "east");
    addFeature("/lib/environment/features/water/canyon-creek.c", "south");

    addExit("north", "/areas/tol-dhurath/forest-1/14x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"gray fox","red fox"}));
}
