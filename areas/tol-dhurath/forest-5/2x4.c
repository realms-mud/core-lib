//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/chokecherry-stand.c", "east");
    addFeature("/lib/environment/features/landforms/hill.c", "east");

    addExit("west", "/areas/tol-dhurath/forest-5/1x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-5/2x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
