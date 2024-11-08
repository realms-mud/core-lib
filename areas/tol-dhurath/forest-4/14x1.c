//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "south");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addFeature("/lib/environment/features/water/canyon-stream.c", "south");

    addExit("south", "/areas/tol-dhurath/forest-4/14x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-4/13x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-4/15x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
