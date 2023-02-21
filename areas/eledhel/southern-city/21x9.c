//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addItem("/lib/environment/items/lighting/window.c", "west");
    addItem("/lib/environment/items/shops/grocer.c");

    addDecorator("2x1 grocer 0x0");
    addExit("west", "/areas/eledhel/southern-city/20x9.c");
    addExitWithDoor("east", "/areas/eledhel/southern-city/22x9.c");
}
