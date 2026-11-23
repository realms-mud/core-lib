//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    setShortDescription("Morleth's study and collection of plant lore");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/desk.c", "east");
    addItem("/lib/environment/items/crafts/mortar-and-pestle.c", "west");
    addExit("west", "/areas/eledhel/northern-city/morleths-stone/0x0.c");
}
