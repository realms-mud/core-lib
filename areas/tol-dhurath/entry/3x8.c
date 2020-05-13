//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hillock.c", "northwest");
    addFeature("/lib/environment/features/water/ravine-brook.c", "southwest");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "east");

    addExit("west", "/areas/tol-dhurath/entry/2x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/entry/4x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
