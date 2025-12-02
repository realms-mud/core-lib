//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "southeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-2/19x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/20x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
