//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/dell.c", "northwest");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-2/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/11x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
