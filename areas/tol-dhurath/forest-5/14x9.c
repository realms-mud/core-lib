//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hollow.c", "southeast");
    addFeature("/lib/environment/features/trees/ash-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/hill.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-5/14x8.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-5/13x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-5/15x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
