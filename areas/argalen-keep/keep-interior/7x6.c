//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setInterior("/lib/environment/interiors/guard-room.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/furniture/rack.c", "north");
    addItem("/lib/environment/items/furniture/chest.c", "west");
    addDecorator("keep interior north alcove");

    addExitWithDoor("south",
        "/areas/argalen-keep/keep-interior/7x5.c");
}
