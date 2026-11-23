//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/guard-room.c");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addItem("/lib/environment/items/objects/flagpole.c", "north");
    addObject("/areas/eledhel/central-city/palace/characters/sendral.c");
    addDecorator("palace 0x1");

    addExit("east", "/areas/eledhel/central-city/palace/1x1.c");
    addExit("south", "/areas/eledhel/central-city/palace/0x2.c");
}
