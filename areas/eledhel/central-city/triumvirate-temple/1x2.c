//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-fortress-hall.c");
    setShortDescription("The Werric outpost's archive room");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addExit("west", "/areas/eledhel/central-city/triumvirate-temple/1x1.c");
}
