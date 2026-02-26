//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setInterior("/lib/environment/interiors/kitchen.c");
    addItem("/lib/environment/items/lighting/hearth.c", "north");
    addItem("/lib/environment/items/furniture/cabinet.c", "east");
    addDecorator("keep interior east entry alcove");

    addExit("west",
        "/areas/argalen-keep/keep-interior/6x2.c");
    addExitWithDoor("north",
        "/areas/argalen-keep/keep-interior/7x3.c");
}
