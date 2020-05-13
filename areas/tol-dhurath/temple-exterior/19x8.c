//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hollow.c", "southwest");
    addFeature("/lib/environment/features/landforms/hill.c", "north");

    addExit("east", "/areas/tol-dhurath/temple-exterior/20x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/temple-exterior/19x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
