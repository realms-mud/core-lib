//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/ridge.c", "east");
    addFeature("/lib/environment/features/trees/maple-stand.c", "west");
    addFeature("/lib/environment/features/landforms/mound.c", "south");

    addExit("north", "/areas/tol-dhurath/forest-3/4x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-3/4x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
