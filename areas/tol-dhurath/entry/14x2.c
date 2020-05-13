//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "east");

    addExit("west", "/areas/tol-dhurath/entry/13x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"white-tail deer","mule deer"}));
}
