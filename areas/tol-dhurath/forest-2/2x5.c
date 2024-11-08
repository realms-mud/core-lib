//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ash-stand.c", "east");
    addFeature("/lib/environment/features/landforms/glen.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-2/2x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-2/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-2/2x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
