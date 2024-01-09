//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "west");
    addFeature("/lib/environment/features/water/gorge-creek.c", "north");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("south", "/areas/tol-dhurath/entry/23x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"white-tail deer","outlaw"}));
}
