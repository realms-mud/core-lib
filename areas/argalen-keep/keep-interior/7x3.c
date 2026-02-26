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
    addItem("/lib/environment/items/lighting/hearth.c", "east");
    addItem("/lib/environment/items/furniture/cabinet.c", "north");
    addItem("/lib/environment/items/furniture/long-table.c", "west");
    addDecorator("keep interior east alcove south entry");

    addExitWithDoor("south",
        "/areas/argalen-keep/keep-interior/7x2.c");
    addExit("north",
        "/areas/argalen-keep/keep-interior/7x4.c");
}
