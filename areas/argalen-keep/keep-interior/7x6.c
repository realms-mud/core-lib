//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setInterior("/lib/environment/interiors/bedroom.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/furniture/bed.c", "north");
    addItem("/lib/environment/items/lighting/lattice-window.c", "north");
    addItem("/lib/environment/items/furniture/dresser.c", "west");
    addItem("/lib/environment/items/furniture/chest.c", "west");
    addDecorator("keep interior northeast corner");

    addExitWithDoor("south",
        "/areas/argalen-keep/keep-interior/7x5.c");
}
