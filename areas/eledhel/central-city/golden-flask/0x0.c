//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    setShortDescription("The common room of the Golden Flask");
    addShop("/lib/environment/shopInventories/provisions.c");
    addItem("/lib/environment/items/furniture/long-table.c", "north");
    addItem("/lib/environment/items/lighting/hearth.c", "east");
    addObject(
        "/areas/eledhel/central-city/characters/golden-flask-innkeeper.c");
    addExit("east", "/areas/eledhel/central-city/golden-flask/1x0.c");
    addExit("south", "/areas/eledhel/central-city/golden-flask/0x1.c");
}
