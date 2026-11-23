//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    addItem("/lib/environment/items/furniture/writing-desk.c", "north");
    addItem("/lib/environment/items/furniture/book-shelf.c", "west");
    addObject("/areas/eledhel/central-city/palace/characters/court-scribe.c");
    addDecorator("palace interior");

    addExit("north", "/areas/eledhel/central-city/palace/1x2.c");
    addExit("east", "/areas/eledhel/central-city/palace/2x3.c");
}
