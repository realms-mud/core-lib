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
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addObject("/areas/items/books/founding-of-eledhel.c");
    addDecorator("keep interior south wall entry");

    addExitWithDoor("south",
        "/areas/argalen-keep/keep-interior/6x5.c");
}
