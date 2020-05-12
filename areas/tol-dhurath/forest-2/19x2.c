//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "northeast");
    addFeature("/lib/environment/features/landforms/ridge.c", "northeast");
    addFeature("/lib/environment/features/landforms/hummock.c", "northeast");

    addExit("south", "/areas/tol-dhurath/forest-2/19x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-2/19x3.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
