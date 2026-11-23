//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/training-fortress.c");
    setShortDescription("The Aegis Academy's instruction room");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/furniture/book-shelf.c", "east");
    addExit("north", "/areas/eledhel/central-city/aegis-academy/0x0.c");
}
