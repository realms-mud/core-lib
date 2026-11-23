//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    setShortDescription("The Aegis Guard's records room");
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/lib/environment/items/furniture/writing-desk.c", "east");
    addExit("north", "/areas/eledhel/central-city/aegis-hall/0x0.c");
    addExit("east", "/areas/eledhel/central-city/aegis-hall/1x1.c");
}
