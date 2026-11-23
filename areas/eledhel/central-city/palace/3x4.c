//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/kitchen.c");
    addItem("/lib/environment/items/furniture/pantry.c", "north");
    addItem("/lib/environment/items/furniture/long-table.c", "east");
    addItem("/lib/environment/items/lighting/hearth.c", "south");
    addDecorator("palace 3x4");

    addExit("west", "/areas/eledhel/central-city/palace/2x4.c");
    addExit("east", "/areas/eledhel/central-city/palace/4x4.c");
    addExit("north", "/areas/eledhel/central-city/palace/3x3.c");
}
