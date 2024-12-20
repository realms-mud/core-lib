//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/mulberry-stand.c", "north");
    addFeature("/lib/environment/features/trees/ash-stand.c", "north");

    addExit("north", "/areas/tol-dhurath/forest-5/2x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-5/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
