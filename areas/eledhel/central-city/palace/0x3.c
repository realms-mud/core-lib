//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/guard-room.c");
    addItem("/lib/environment/items/furniture/bench.c", "east");
    addObject("/areas/eledhel/central-city/palace/characters/palace-guard.c");
    addDecorator("palace 0x1");

    addExit("north", "/areas/eledhel/central-city/palace/0x2.c");
    addExit("east", "/areas/eledhel/central-city/palace/1x3.c");
}
