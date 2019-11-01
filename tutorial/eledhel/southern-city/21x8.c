//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addItem("/lib/environment/items/lighting/window.c", "west");

    addDecorator("2x1 shipwright 0x0");
    addExit("west", "/lib/tutorial/eledhel/southern-city/20x8.c");
    addExitWithDoor("east", "/lib/tutorial/eledhel/southern-city/22x8.c");
}
