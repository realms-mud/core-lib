//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    addItem("/lib/environment/items/furniture/writing-desk.c", "north");
    addItem("/lib/environment/items/furniture/book-shelf.c", "east");
    addDecorator("palace 4x0");

    addExit("west", "/areas/eledhel/central-city/palace/3x0.c");
    addExit("south", "/areas/eledhel/central-city/palace/4x1.c");
    addExit("east", "/areas/eledhel/central-city/palace/5x0.c");
}
