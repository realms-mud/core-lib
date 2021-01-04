//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addItem("/lib/environment/items/lighting/window.c", "west");

    addDecorator("2x1 shipwright 0x0");
    addExit("west", "/areas/eledhel/southern-city/20x8.c");
    addExitWithDoor("east", "/areas/eledhel/southern-city/22x8.c");
}
