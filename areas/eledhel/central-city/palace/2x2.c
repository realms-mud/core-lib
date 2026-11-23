//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/furniture/chair.c", "east");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addDecorator("palace interior");

    addExit("north", "/areas/eledhel/central-city/palace/2x1.c");
    addExit("east", "/areas/eledhel/central-city/palace/3x2.c");
    addExit("west", "/areas/eledhel/central-city/palace/1x2.c");
    addExit("south", "/areas/eledhel/central-city/palace/2x3.c");
}
