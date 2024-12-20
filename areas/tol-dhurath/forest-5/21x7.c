//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "northwest");

    addExit("north", "/areas/tol-dhurath/forest-5/21x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");

    addRandomCreature(({"zombie","beaver","skunk","porcupine","red squirrel","opossum"}));
}
