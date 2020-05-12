//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "south");

    addExit("west", "/areas/tol-dhurath/entry/22x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"black bear","skeleton","undead"}));
}
