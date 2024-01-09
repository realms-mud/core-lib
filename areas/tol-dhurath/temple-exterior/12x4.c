//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "south");
    addFeature("/lib/environment/features/trees/paper-birch-stand.c", "north");

    addExit("east", "/areas/tol-dhurath/temple-exterior/13x4.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/temple-exterior/11x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
