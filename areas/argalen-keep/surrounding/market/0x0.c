//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/furniture/small-shelf.c", "east");
    addItem("/lib/environment/items/furniture/small-shelf.c", "west");
    addShop("/lib/environment/shopInventories/apothecary.c");

    addObject("/areas/argalen-keep/surrounding/characters/marta/marta.c");

    addExitWithDoor("west", "/areas/argalen-keep/surrounding/13x5.c");
}
