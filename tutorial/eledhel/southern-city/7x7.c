//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/opulent-shop.c");
    addShop("/lib/environment/shopInventories/mage-shop.c");
    addItem("/lib/environment/items/lighting/window.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/lighting/sconce.c", "north");

    addDecorator("1x1 building arcane");
    addExitWithDoor("west", "/lib/tutorial/eledhel/southern-city/6x7.c");
}
