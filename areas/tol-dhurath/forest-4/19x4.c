//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "west");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "west");
    addFeature("/lib/environment/features/landforms/hummock.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-4/18x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-4/19x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
