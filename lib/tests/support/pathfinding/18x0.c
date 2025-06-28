//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/dell.c", "northwest");
    addFeature("/lib/environment/features/trees/alder-stand.c", "northwest");
    addFeature("/lib/environment/features/trees/poplar-stand.c", "northwest");

    addExit("east", "/lib/tests/support/pathfinding/19x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/lib/tests/support/pathfinding/18x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}

