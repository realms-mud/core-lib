//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "northeast");
    addFeature("/lib/environment/features/water/ravine-brook.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-2/11x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-2/10x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
