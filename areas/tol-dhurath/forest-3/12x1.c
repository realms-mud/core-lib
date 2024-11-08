//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/combe.c", "south");
    addFeature("/lib/environment/features/landforms/tor.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-3/12x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-3/12x2.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-3/11x1.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
