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
    addDecorator("keep interior north T-intersection south entry");

    addExitWithDoor("south",
        "/areas/argalen-keep/keep-interior/7x4.c");
    addExit("west",
        "/areas/argalen-keep/keep-interior/6x5.c");
    addExitWithDoor("north",
        "/areas/argalen-keep/keep-interior/7x6.c");
}
