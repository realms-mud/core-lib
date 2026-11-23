//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    addShop("/lib/environment/shopInventories/provisions.c");
    addObject("/areas/eledhel/southern-city/characters/innkeeper.c");
    addObject("/areas/eledhel/southern-city/characters/inn-guest.c");
    addItem("/lib/environment/items/lighting/window.c", "west");

    addExitWithDoor("west", "/areas/eledhel/southern-city/16x3.c");
}
