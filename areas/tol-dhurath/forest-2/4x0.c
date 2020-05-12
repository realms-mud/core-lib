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
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");

    addExit("west", "/areas/tol-dhurath/forest-2/3x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-2/4x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
