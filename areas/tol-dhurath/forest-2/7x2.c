//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northeast");
    addFeature("/lib/environment/features/trees/walnut-stand.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-2/8x2.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-2/7x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-2/6x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
