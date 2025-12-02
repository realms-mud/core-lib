//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "west");
    addFeature("/lib/environment/features/trees/mulberry-stand.c", "west");
    addFeature("/lib/environment/features/trees/grape-stand.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-4/16x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-4/18x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
