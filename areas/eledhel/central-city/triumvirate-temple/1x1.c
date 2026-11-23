//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-temple.c");
    setShortDescription("The great hall of the Temple of the Triumvirate");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/furniture/book-shelf.c", "east");
    addObject(
        "/areas/eledhel/central-city/characters/werric-instructor.c");
    addExit("north", "/areas/eledhel/central-city/triumvirate-temple/0x1.c");
    addExit("east", "/areas/eledhel/central-city/triumvirate-temple/1x2.c");
}
