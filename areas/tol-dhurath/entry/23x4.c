//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "north");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "west");
    addFeature("/lib/environment/features/trees/maple-stand.c", "southwest");

    addExit("east", "/areas/tol-dhurath/entry/24x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/entry/23x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
