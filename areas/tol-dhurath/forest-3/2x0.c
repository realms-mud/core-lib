//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "north");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-3/1x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-3/3x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
