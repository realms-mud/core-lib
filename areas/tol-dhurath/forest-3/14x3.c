//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");
    addFeature("/lib/environment/features/landforms/glen.c", "northeast");
    addFeature("/lib/environment/features/trees/hemlock-stand.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-3/14x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-3/13x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/forest-3/15x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
