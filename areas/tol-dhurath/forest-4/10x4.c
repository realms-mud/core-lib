//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/red-oak-stand.c", "southwest");
    addFeature("/lib/environment/features/landforms/dell.c", "southwest");

    addExit("west", "/areas/tol-dhurath/forest-4/9x4.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-4/10x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
