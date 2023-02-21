//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hummock.c", "east");
    addFeature("/lib/environment/features/trees/winesap-apple-stand.c", "east");

    addExit("west", "/areas/tol-dhurath/forest-4/8x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-4/9x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
