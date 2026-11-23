//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    addItem("/lib/environment/items/furniture/bench.c", "north");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addDecorator("palace 1x0");

    addExit("west", "/areas/eledhel/central-city/palace/0x0.c");
    addExit("east", "/areas/eledhel/central-city/palace/2x0.c");
    addExit("south", "/areas/eledhel/central-city/palace/1x1.c");
}
