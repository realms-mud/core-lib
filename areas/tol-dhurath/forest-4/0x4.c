//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");

    addExit("south", "/areas/tol-dhurath/forest-4/0x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"weasel","ruffian","zombie","skunk","brown bear","raccoon"}));
}
