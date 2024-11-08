//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("east", "/areas/tol-dhurath/temple-exterior/19x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/temple-exterior/18x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
