//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/waterfall.c", "west");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");
    addFeature("/lib/environment/features/water/gulley-creek.c", "west");

    addExit("west", "/areas/tol-dhurath/forest-4/21x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-4/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-4/22x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
