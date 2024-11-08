//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/red-oak-stand.c", "southeast");

    addExit("north", "/areas/tol-dhurath/forest-5/19x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-5/18x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"ruffian","timber wolf"}));
}
