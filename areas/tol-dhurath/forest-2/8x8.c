//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-creek.c", "northeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-2/9x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-2/8x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"white-tail deer","coyote"}));
}
