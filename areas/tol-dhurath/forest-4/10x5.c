//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "east");
    addFeature("/lib/environment/features/trees/elm-stand.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "east");

    addExit("south", "/areas/tol-dhurath/forest-4/10x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-4/11x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
