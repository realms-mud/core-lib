//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addShop("/lib/environment/shopInventories/jeweler.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "west");

    addDecorator("1x1 building jeweler");
    addExitWithDoor("west", "/areas/eledhel/southern-city/12x6.c");
}
