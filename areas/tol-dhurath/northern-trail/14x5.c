//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addItem("/lib/environment/items/lighting/window.c", "north");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addItem("/lib/environment/items/objects/milestone.c", "east");

    addExit("south", "/areas/tol-dhurath/northern-trail/14x4.c");
}
