//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    setShortDescription("The public library's quiet entrance hall");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addObject(
        "/areas/eledhel/northern-city/characters/library-copyist.c");
    addExit("south", "/areas/eledhel/northern-city/18x8.c");
    addExit("east", "/areas/eledhel/northern-city/library/1x0.c");
}
