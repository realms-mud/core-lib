//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/waterfall.c", "southwest");

    addExit("east", "/areas/tol-dhurath/forest-2/19x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-2/18x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"black bear","keeper of the night","outlaw","timber wolf"}));
}
