//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addShop("/lib/environment/shopInventories/bowyer.c");
    addItem("/lib/environment/items/lighting/window.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");

    addDecorator("2x1 bowyer 1x0");
    addExitWithDoor("west", "/areas/eledhel/southern-city/15x9.c");
    addExitWithDoor("east", "/areas/eledhel/southern-city/17x9.c");
}
