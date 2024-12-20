//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/promontory.c", "east");
    addFeature("/lib/environment/features/trees/alder-stand.c", "east");
    addFeature("/lib/environment/features/trees/beech-stand.c", "east");

    addExit("south", "/areas/tol-dhurath/forest-5/3x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-5/3x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
