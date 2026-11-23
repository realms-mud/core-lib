//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/opulent-entry.c");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addObject("/areas/eledhel/central-city/palace/characters/petitioner.c");
    addDecorator("palace interior");

    addExit("north", "/areas/eledhel/central-city/palace/1x1.c");
    addExit("east", "/areas/eledhel/central-city/palace/2x2.c");
    addExit("west", "/areas/eledhel/central-city/palace/0x2.c");
    addExit("south", "/areas/eledhel/central-city/palace/1x3.c");
}
