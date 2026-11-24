//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("A concealed records room behind the west wall");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/book-shelf.c", "south");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addItem(
        "/lib/environment/items/objects/hidden-field-dispatches.c", "none");
    addExit("east",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x3.c");
}
