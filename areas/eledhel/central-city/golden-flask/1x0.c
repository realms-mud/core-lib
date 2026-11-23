//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/kitchen.c");
    setShortDescription("The kitchen of the Golden Flask");
    addItem("/lib/environment/items/furniture/pantry.c", "north");
    addItem("/lib/environment/items/furniture/long-table.c", "east");
    addExit("west", "/areas/eledhel/central-city/golden-flask/0x0.c");
}
