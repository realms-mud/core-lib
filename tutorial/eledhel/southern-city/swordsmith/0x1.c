//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/limestone-interior-shop.c");
    addItem("/lib/environment/items/lighting/sconce.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "west");

    addExitWithDoor("west", "/lib/tutorial/eledhel/southern-city/17x8.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/swordsmith/1x1.c");
    addExit("north", "/lib/tutorial/eledhel/southern-city/swordsmith/0x2.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/swordsmith/0x0.c");
}
