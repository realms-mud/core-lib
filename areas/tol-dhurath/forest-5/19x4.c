//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "southeast");

    addExit("north", "/areas/tol-dhurath/forest-5/19x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-5/19x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"gray fox","black bear","muskrat","outlaw","porcupine"}));
}
