//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/glen.c", "northeast");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("north", "/areas/tol-dhurath/forest-3/7x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-3/7x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
