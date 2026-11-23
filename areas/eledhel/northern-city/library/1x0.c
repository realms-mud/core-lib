//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    setShortDescription("The library's genealogy and military shelves");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/tall-shelf.c", "east");
    addItem("/lib/environment/items/furniture/desk.c", "west");
    addExit("west", "/areas/eledhel/northern-city/library/0x0.c");
    addExit("east", "/areas/eledhel/northern-city/library/2x0.c");
}
