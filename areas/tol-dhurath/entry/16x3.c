//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");
    addFeature("/lib/environment/features/landforms/promontory.c", "north");
    addFeature("/lib/environment/features/trees/ash-stand.c", "west");

    addExit("east", "/areas/tol-dhurath/entry/17x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/entry/16x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
