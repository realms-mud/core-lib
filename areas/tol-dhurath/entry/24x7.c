//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/pond.c", "north");
    addFeature("/lib/environment/features/trees/honeycrisp-apple-stand.c", "north");
    addFeature("/lib/environment/features/landforms/ridge.c", "north");

    addExit("west", "/areas/tol-dhurath/entry/23x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("south", "/areas/tol-dhurath/entry/24x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
