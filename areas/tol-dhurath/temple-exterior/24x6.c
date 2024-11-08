//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "east");
    addFeature("/lib/environment/features/landforms/hill.c", "west");

    addExit("south", "/areas/tol-dhurath/temple-exterior/24x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/temple-exterior/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
