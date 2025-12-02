//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addExit("west", "/lib/tests/support/pathfinding/14x5.c");
    addExit("north", "/lib/tests/support/pathfinding/15x6.c");
    addExit("south", "/lib/tests/support/pathfinding/15x4.c");
}
