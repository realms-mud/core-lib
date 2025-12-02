//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "north");
    addFeature("/lib/environment/features/landforms/glen.c", "east");
    addFeature("/lib/environment/features/trees/holly-stand.c", "northeast");

    addExit("west", "/areas/tol-dhurath/forest-1/3x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/tol-dhurath/forest-1/4x6.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
