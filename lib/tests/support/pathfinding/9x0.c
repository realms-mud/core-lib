//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addExit("east", "/lib/tests/support/pathfinding/10x0.c");
    addExit("west", "/lib/tests/support/pathfinding/8x0.c");
    addExit("north", "/lib/tests/support/pathfinding/9x1.c");
}
