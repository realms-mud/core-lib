//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/vale.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "north");

    addExit("west", "/areas/tol-dhurath/forest-3/9x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/forest-3/10x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
