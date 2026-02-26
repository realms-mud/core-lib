//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setInterior("/lib/environment/interiors/gate-house.c");
    addItem("/lib/environment/items/lighting/lit-torch.c", "east");
    addItem("/lib/environment/items/lighting/lit-torch.c", "west");
    addDecorator("keep interior south gatehouse");

    addExit("south",
        "/areas/argalen-keep/surrounding/12x8.c");
    addExit("north",
        "/areas/argalen-keep/keep-interior/5x1.c");
}
