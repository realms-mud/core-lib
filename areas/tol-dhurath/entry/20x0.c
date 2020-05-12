//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/alp.c", "south");
    addFeature("/lib/environment/features/water/ravine-dry-creek.c", "south");

    addExit("west", "/areas/tol-dhurath/entry/19x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("east", "/areas/tol-dhurath/entry/21x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
