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
    addFeature("/lib/environment/features/landforms/ridge.c", "north");

    addExit("east", "/areas/tol-dhurath/forest-4/24x9.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-4/22x9.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
