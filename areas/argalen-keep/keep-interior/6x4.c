//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setInterior("/lib/environment/interiors/hallway.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addDecorator("keep interior east-west hallway");

    addExit("west",
        "/areas/argalen-keep/keep-interior/5x4.c");
    addExit("east",
        "/areas/argalen-keep/keep-interior/7x4.c");
    addExit("south",
        "/areas/argalen-keep/keep-interior/6x3.c");
}
