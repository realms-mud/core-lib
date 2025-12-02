//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northwest");
    addFeature("/lib/environment/features/trees/holly-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");

    addExit("west", "/areas/tol-dhurath/forest-5/1x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-5/2x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
