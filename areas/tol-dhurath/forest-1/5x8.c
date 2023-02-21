//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "west");
    addFeature("/lib/environment/features/trees/maple-stand.c", "south");
    addFeature("/lib/environment/features/trees/apple-stand.c", "east");

    addExit("south", "/areas/tol-dhurath/forest-1/5x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-1/6x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
