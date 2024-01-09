//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/combe.c", "southeast");
    addFeature("/lib/environment/features/landforms/knoll.c", "north");

    addExit("south", "/areas/tol-dhurath/entry/15x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/entry/15x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
