//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "northwest");
    addFeature("/lib/environment/features/water/ravine-brook.c", "northwest");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-4/24x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-4/23x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
