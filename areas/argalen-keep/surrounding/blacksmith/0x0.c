//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addItem("/lib/environment/items/lighting/forge-fire.c", "north");
    addItem("/lib/environment/items/lighting/window.c", "west");
    addItem("/lib/environment/items/furniture/rack.c", "east");
    addItem("/lib/environment/items/furniture/coffer.c", "south");
    addShop("/lib/environment/shopInventories/swordsmith.c");

    addObject("/areas/argalen-keep/surrounding/characters/branna/branna.c");

    addExitWithDoor("west", "/areas/argalen-keep/surrounding/12x4.c");
}
