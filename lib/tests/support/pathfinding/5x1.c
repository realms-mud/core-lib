//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addExit("east", "/lib/tests/support/pathfinding/6x1.c");
    addExit("west", "/lib/tests/support/pathfinding/4x1.c");
    addExit("south", "/lib/tests/support/pathfinding/5x0.c");
    addExit("north", "/lib/tests/support/pathfinding/5x2.c");
}
