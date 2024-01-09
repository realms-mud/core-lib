//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/buckeye-stand.c", "southwest");
    addFeature("/lib/environment/features/trees/elm-stand.c", "southwest");

    addExit("south", "/areas/tol-dhurath/forest-5/14x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-5/14x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
