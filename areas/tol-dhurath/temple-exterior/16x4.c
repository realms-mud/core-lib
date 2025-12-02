//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/pond.c", "east");
    addFeature("/lib/environment/features/landforms/hollow.c", "north");

    addExit("west", "/areas/tol-dhurath/temple-exterior/15x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/temple-exterior/17x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
