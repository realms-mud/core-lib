//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "southwest");
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");
    addFeature("/lib/environment/features/trees/rosewood-stand.c", "northeast");

    addExit("south", "/areas/tol-dhurath/forest-2/15x1.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/tol-dhurath/forest-2/14x2.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
