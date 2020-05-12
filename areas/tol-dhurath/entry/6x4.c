//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/red-oak-stand.c", "south");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addFeature("/lib/environment/features/trees/spruce-stand.c", "south");

    addExit("north", "/areas/tol-dhurath/entry/6x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/entry/6x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
