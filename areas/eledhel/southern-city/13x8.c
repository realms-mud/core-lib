//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");

    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/lighting/window.c", "north");

    addDecorator("1x1 building type 4");
    addExitWithDoor("west", "/areas/eledhel/southern-city/12x8.c");
}
