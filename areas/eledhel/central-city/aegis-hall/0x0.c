//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-fortress-hall.c");
    setShortDescription("The reception hall of the Aegis Guard");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addItem("/lib/environment/items/objects/notice-board.c", "north");
    addObject(
        "/areas/eledhel/central-city/characters/aegis-recruiter.c");
    addExit("east", "/areas/eledhel/central-city/aegis-hall/1x0.c");
    addExit("south", "/areas/eledhel/central-city/aegis-hall/0x1.c");
}
