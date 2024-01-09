//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southeast");

    addExit("north", "/areas/tol-dhurath/forest-5/7x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"red fox","outlaw","moose","opossum","chipmunk"}));
}
