//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/cliff.c", "southeast");
    addFeature("/lib/environment/features/trees/red-oak-stand.c", "southeast");

    addExit("east", "/lib/tests/support/pathfinding/9x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/lib/tests/support/pathfinding/7x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}

