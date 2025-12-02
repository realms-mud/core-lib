//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/elm-stand.c", "south");
    addFeature("/lib/environment/features/trees/birch-stand.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "northwest");

    addExit("east", "/areas/tol-dhurath/temple-exterior/6x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/temple-exterior/4x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
