//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/gate-house.c");
    addItem("/lib/environment/items/furniture/counter.c", "east");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addDecorator("palace west gate");

    addExit("west", "/areas/eledhel/central-city/14x5.c");
    addExit("north", "/areas/eledhel/central-city/palace/0x1.c");
    addExit("east", "/areas/eledhel/central-city/palace/1x2.c");
    addExit("south", "/areas/eledhel/central-city/palace/0x3.c");
}
