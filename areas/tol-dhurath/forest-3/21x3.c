//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/birch-stand.c", "southeast");
    addFeature("/lib/environment/features/trees/pine-stand.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-3/21x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-3/22x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-3/21x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
