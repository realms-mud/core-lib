//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/creek.c", "northeast");
    addFeature("/lib/environment/features/trees/maple-stand.c", "northeast");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "northeast");

    addExit("east", "/lib/tests/support/pathfinding/4x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/2x7.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

