//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/tor.c", "north");
    addFeature("/lib/environment/features/water/waterfall.c", "east");

    addExit("west", "/areas/tol-dhurath/temple-exterior/13x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/temple-exterior/14x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
