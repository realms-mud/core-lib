//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "east");
    addFeature("/lib/environment/features/trees/beech-stand.c", "south");

    addExit("north", "/areas/tol-dhurath/forest-2/1x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-2/2x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
