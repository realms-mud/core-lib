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
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/writing-desk.c", "east");
    addItem("/lib/environment/items/lighting/candelabra.c", "west");
    addObject("/areas/items/books/chronicles-of-eledhel.c");
    addDecorator("keep interior northeast corner east entry");

    addExitWithDoor("east",
        "/areas/argalen-keep/keep-interior/5x6.c");
}
