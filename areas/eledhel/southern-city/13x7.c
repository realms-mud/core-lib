//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addShop("/lib/environment/shopInventories/gem-crafter.c");
    addObject("/areas/eledhel/southern-city/characters/miraen/miraen.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "west");

    addDecorator("1x1 building gem merchant");
    addExitWithDoor("west", "/areas/eledhel/southern-city/12x7.c");
}
