//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/desk.c", "east");
    addDecorator("palace 2x0");

    addExit("west", "/areas/eledhel/central-city/palace/1x0.c");
    addExit("east", "/areas/eledhel/central-city/palace/3x0.c");
    addExit("south", "/areas/eledhel/central-city/palace/2x1.c");
}
