//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addDecorator("keep interior south-west corner hallway");
    setShortDescription("The garden supply shop");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/small-shelf.c", "east");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "north");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addShop("/lib/environment/shopInventories/apothecary.c");
    addExitWithDoor("south", "/areas/minlach/3x3.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("west", "/areas/minlach/2x4.c",
        "/lib/environment/doors/plank-door.c");
}
