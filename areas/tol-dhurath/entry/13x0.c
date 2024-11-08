//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "southwest");

    addExit("north", "/areas/tol-dhurath/entry/13x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/entry/12x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
