//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setInterior("/lib/environment/interiors/banquet-hall.c");
    addItem("/lib/environment/items/lighting/chandelier.c", "south");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addDecorator("keep interior floor");

    addExit("south",
        "/areas/argalen-keep/keep-interior/5x2.c");
    addExit("west",
        "/areas/argalen-keep/keep-interior/4x3.c");
    addExit("east",
        "/areas/argalen-keep/keep-interior/6x3.c");
    addExit("north",
        "/areas/argalen-keep/keep-interior/5x4.c");
}
