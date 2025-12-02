//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/buckeye-stand.c", "west");
    addFeature("/lib/environment/features/water/pond.c", "west");
    addFeature("/lib/environment/features/trees/maple-stand.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-4/14x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-4/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
