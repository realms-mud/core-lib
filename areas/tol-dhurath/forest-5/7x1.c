//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/water/gulley-creek.c", "west");

    addExit("east", "/areas/tol-dhurath/forest-5/8x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-5/6x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"fisher","otter","porcupine","red squirrel","mink"}));
}
