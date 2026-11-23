//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addShop("/lib/environment/shopInventories/herbalist.c");
    addItem("/lib/environment/items/crafts/mortar-and-pestle.c", "north");
    addItem("/lib/environment/items/furniture/herb-drying-rack.c", "east");
    addObject("/areas/eledhel/northern-city/characters/morleth.c");
    addObject("/areas/eledhel/northern-city/characters/herbalist-customer.c");
    addExit("north", "/areas/eledhel/northern-city/21x8.c");
    addExit("east", "/areas/eledhel/northern-city/morleths-stone/1x0.c");
}
