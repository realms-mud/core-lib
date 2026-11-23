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
    addObject("/areas/eledhel/central-city/palace/characters/court-advisor.c");
    addDecorator("palace 3x0");

    addExit("west", "/areas/eledhel/central-city/palace/2x0.c");
    addExit("east", "/areas/eledhel/central-city/palace/4x0.c");
    addExit("south", "/areas/eledhel/central-city/palace/3x1.c");
}
