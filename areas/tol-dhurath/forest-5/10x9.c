//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "south");

    addExit("east", "/areas/tol-dhurath/forest-5/11x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-5/9x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"fisher","zombie","weasel","gray fox","warg"}));
}
