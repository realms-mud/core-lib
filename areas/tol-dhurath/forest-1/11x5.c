//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "northwest");
    addFeature("/lib/environment/features/water/gulley-creek.c", "northwest");
    addFeature("/lib/environment/features/landforms/ridge.c", "northwest");

    addExit("east", "/areas/tol-dhurath/forest-1/12x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-1/11x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
