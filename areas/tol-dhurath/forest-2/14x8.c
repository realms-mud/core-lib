//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/ambrosia-apple-stand.c", "north");
    addFeature("/lib/environment/features/landforms/glen.c", "south");

    addExit("west", "/areas/tol-dhurath/forest-2/13x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-2/15x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-2/14x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
