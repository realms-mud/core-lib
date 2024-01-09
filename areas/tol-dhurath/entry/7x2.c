//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/gulley-creek.c", "west");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "north");

    addExit("south", "/areas/tol-dhurath/entry/7x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/entry/7x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
