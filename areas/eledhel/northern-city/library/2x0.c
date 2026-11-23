//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    setShortDescription("The library's histories and legends");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/book-shelf.c", "east");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "south");
    addExit("west", "/areas/eledhel/northern-city/library/1x0.c");
}
