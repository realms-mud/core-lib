//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-brook.c", "northwest");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "northwest");
    addFeature("/lib/environment/features/water/gorge-creek.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-1/24x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/24x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
