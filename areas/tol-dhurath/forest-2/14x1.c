//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/lake.c", "east");
    addFeature("/lib/environment/features/trees/elm-stand.c", "west");

    addExit("north", "/areas/tol-dhurath/forest-2/14x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-2/14x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
