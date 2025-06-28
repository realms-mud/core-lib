//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/brook.c", "southwest");
    addFeature("/lib/environment/features/landforms/crag.c", "southwest");
    addFeature("/lib/environment/features/trees/holly-stand.c", "southwest");

    addExit("north", "/lib/tests/support/pathfinding/24x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/lib/tests/support/pathfinding/23x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

