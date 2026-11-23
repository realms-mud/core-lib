//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-fortress-hall.c");
    setShortDescription("The Aegis Guard's command room");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/objects/notice-board.c", "east");
    addExit("west", "/areas/eledhel/central-city/aegis-hall/0x0.c");
    addExit("south", "/areas/eledhel/central-city/aegis-hall/1x1.c");
}
