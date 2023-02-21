//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "northeast");
    addFeature("/lib/environment/features/landforms/mound.c", "northwest");
    addFeature("/lib/environment/features/water/canyon-brook.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-1/11x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/11x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
