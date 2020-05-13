//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/red-oak-stand.c", "north");
    addFeature("/lib/environment/features/landforms/dell.c", "south");
    addFeature("/lib/environment/features/landforms/combe.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-3/4x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-3/3x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-3/2x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
