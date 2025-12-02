//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "west");
    addFeature("/lib/environment/features/landforms/dell.c", "south");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-2/10x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/11x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
