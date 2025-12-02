//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gorge-creek.c", "southeast");

    addExit("east", "/areas/tol-dhurath/forest-3/12x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"hunter","ruffian","coyote","mule deer","outlaw","moose"}));
}
