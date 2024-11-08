//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "east");
    addFeature("/lib/environment/features/water/river.c", "east");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "east");

    addExit("north", "/areas/tol-dhurath/forest-5/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-5/2x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"ruffian","zombie","otter","mink"}));
}
