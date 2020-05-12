//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/water/gulley-creek.c", "southwest");

    addExit("east", "/areas/tol-dhurath/forest-2/2x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"black bear","ruffian","outlaw","white-tail deer","gray wolf"}));
}
