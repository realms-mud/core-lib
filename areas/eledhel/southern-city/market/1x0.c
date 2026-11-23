//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/brick-interior-shop.c");
    addItem("/lib/environment/items/furniture/chest.c", "north");
    addItem("/lib/environment/items/furniture/table.c", "south");

    addExit("west", "/areas/eledhel/southern-city/market/0x0.c");
}
