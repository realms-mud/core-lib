//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "south");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "west");
    addFeature("/lib/environment/features/water/gorge-creek.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-1/24x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
