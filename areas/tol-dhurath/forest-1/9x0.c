//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "southeast");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");
    addFeature("/lib/environment/features/water/gorge-creek.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-1/10x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"outlaw","coyote","white-tail deer","beaver","mink"}));
}
