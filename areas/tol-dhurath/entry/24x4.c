//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/maple-stand.c", "north");
    addFeature("/lib/environment/features/water/lake-shore-bluff.c", "northeast");

    addExit("north", "/areas/tol-dhurath/entry/24x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/entry/23x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
