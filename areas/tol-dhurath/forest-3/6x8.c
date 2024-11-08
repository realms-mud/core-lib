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
    addFeature("/lib/environment/features/landforms/butte.c", "north");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northeast");

    addExit("west", "/areas/tol-dhurath/forest-3/5x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-3/7x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
