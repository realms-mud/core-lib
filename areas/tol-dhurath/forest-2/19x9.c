//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-2/19x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"hunter","zombie","black bear","ruffian","outlaw","coyote","kit fox"}));
}
