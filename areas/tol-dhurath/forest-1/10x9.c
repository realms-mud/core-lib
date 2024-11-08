//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/chokecherry-stand.c", "west");
    addFeature("/lib/environment/features/trees/birch-stand.c", "north");
    addFeature("/lib/environment/features/water/lake.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-1/9x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-1/11x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
