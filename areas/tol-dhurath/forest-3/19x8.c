//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-3/20x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addRandomCreature(({"outlaw","ruffian","muskrat","timber wolf"}));
}
