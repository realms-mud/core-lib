//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "south");

    addExit("east", "/areas/tol-dhurath/forest-5/5x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-5/3x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
