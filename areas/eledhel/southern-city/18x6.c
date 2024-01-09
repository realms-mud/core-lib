//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/brick-interior-shop.c");
    addShop("/lib/environment/shopInventories/armorer.c");
    addItem("/lib/environment/items/lighting/window.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");

    addDecorator("1x1 building armorer 2");
    addExitWithDoor("west", "/areas/eledhel/southern-city/17x6.c");
}
