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
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");

    addExit("north", "/areas/tol-dhurath/forest-2/14x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-2/13x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
