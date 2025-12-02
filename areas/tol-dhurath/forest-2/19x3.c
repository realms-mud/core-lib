//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/hillock.c", "north");
    addFeature("/lib/environment/features/water/canyon-creek.c", "east");
    addFeature("/lib/environment/features/landforms/mound.c", "west");

    addExit("south", "/areas/tol-dhurath/forest-2/19x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-2/19x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
