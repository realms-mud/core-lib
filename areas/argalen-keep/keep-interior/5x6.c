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
    addItem("/lib/environment/items/lighting/fireplace.c", "north");
    addItem("/lib/environment/items/furniture/canopy-bed.c", "west");
    addItem("/lib/environment/items/furniture/armoire.c", "east");
    addItem("/lib/environment/items/lighting/candelabra.c", "south");
    addDecorator("keep interior north alcove");

    addExitWithDoor("south",
        "/areas/argalen-keep/keep-interior/5x5.c");
}
