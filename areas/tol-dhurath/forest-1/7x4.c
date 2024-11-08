//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "west");
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");

    addExit("south", "/areas/tol-dhurath/forest-1/7x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-1/7x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-1/6x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
