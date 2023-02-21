//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cherry-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/buckthorn-stand.c", "north");

    addExit("south", "/areas/tol-dhurath/forest-3/24x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-3/24x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
