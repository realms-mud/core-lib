//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/sandy-lake-beach.c", "south");
    addFeature("/lib/environment/features/landforms/valley.c", "northeast");

    addExit("east", "/areas/tol-dhurath/forest-3/14x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-3/12x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
