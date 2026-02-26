//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setInterior("/lib/environment/interiors/library.c");
    addItem("/lib/environment/items/lighting/candelabra.c", "north");
    addItem("/lib/environment/items/furniture/book-shelf.c", "west");
    addItem("/lib/environment/items/furniture/book-shelf.c", "east");
    addItem("/lib/environment/items/furniture/writing-desk.c", "south");
    addDecorator("keep interior north alcove");

    addExitWithDoor("south",
        "/areas/argalen-keep/keep-interior/3x5.c");
}
