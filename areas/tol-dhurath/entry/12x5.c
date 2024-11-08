//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "southeast");

    addExit("north", "/areas/tol-dhurath/entry/12x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/entry/11x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
