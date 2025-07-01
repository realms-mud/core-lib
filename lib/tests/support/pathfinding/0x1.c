//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");    
    addExit("south", "/lib/tests/support/pathfinding/0x0.c");
    addExit("north", "/lib/tests/support/pathfinding/0x2.c");
}
