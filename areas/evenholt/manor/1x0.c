//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    addDecorator("keep interior south T-intersection");
    setShortDescription("The small library");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/writing-desk.c", "south");
    addExit("west", "/areas/evenholt/manor/0x0.c");
    addExit("east", "/areas/evenholt/manor/2x0.c");
    addExit("south", "/areas/evenholt/manor/1x1.c");
}
