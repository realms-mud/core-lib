//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "west");
    addFeature("/lib/environment/features/landforms/knoll.c", "southeast");

    addExit("south", "/areas/tol-dhurath/entry/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/entry/15x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
