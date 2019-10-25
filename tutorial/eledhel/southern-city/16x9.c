//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addItem("/lib/environment/items/lighting/sconce.c", "north");

    addDecorator("2x1 building 1x0 door");
    addExitWithDoor("west", "/lib/tutorial/eledhel/southern-city/15x9.c");
    addExitWithDoor("east", "/lib/tutorial/eledhel/southern-city/17x9.c");
}
