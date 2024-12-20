//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/precipice.c", "southeast");
    addFeature("/lib/environment/features/trees/pine-stand.c", "northwest");

    addExit("east", "/areas/tol-dhurath/entry/13x8.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/tol-dhurath/entry/12x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
