//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/pine-stand.c", "south");
    addFeature("/lib/environment/features/trees/beech-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/butte.c", "east");

    addExit("north", "/areas/tol-dhurath/forest-1/7x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-1/8x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-1/6x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
