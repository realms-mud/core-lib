//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The naval chart and command room");
    addItem("/lib/environment/items/furniture/writing-desk.c", "north");
    addItem("/lib/environment/items/furniture/book-shelf.c", "east");
    addObject("/areas/eledhel/northern-city/characters/naval-commander.c");
    addExit("west", "/areas/eledhel/northern-city/naval-headquarters/0x0.c");
    addExit("north", "/areas/eledhel/northern-city/naval-headquarters/1x1.c");
}
