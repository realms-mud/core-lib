//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/winesap-apple-stand.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-4/22x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-4/24x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"white-tail deer","boar","porcupine"}));
}
