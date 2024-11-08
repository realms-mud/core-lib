//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-2/8x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-2/9x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
