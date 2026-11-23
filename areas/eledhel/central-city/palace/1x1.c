//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/banquet-hall.c");
    addItem("/lib/environment/items/furniture/dais-with-thrones.c", "north");
    addItem("/lib/environment/items/furniture/long-table.c", "east");
    addItem("/lib/environment/items/lighting/chandelier.c", "west");
    addDecorator("palace interior");
    addObject("/areas/eledhel/central-city/palace/characters/ardenel.c");
    addObject("/areas/eledhel/central-city/palace/characters/arueil.c");
    addObject("/areas/eledhel/central-city/palace/characters/aredec.c");

    addExit("west", "/areas/eledhel/central-city/palace/0x1.c");
    addExit("east", "/areas/eledhel/central-city/palace/2x1.c");
    addExit("south", "/areas/eledhel/central-city/palace/1x2.c");
}
