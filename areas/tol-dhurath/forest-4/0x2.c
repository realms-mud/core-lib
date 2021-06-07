//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cherry-stand.c", "northeast");
    addFeature("/lib/environment/features/water/waterfall.c", "northeast");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-4/1x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
