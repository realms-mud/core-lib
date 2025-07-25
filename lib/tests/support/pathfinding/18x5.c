//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addExit("east", "/lib/tests/support/pathfinding/19x5.c");
    addExit("west", "/lib/tests/support/pathfinding/17x5.c");
    addExit("south", "/lib/tests/support/pathfinding/18x4.c");
}
