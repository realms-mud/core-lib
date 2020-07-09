//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/limestone-interior-shop.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "west");

    addExitWithDoor("west", "/areas/eledhel/southern-city/17x8.c");
    addExit("east", "/areas/eledhel/southern-city/swordsmith/1x1.c");
    addExit("north", "/areas/eledhel/southern-city/swordsmith/0x2.c");
    addExit("south", "/areas/eledhel/southern-city/swordsmith/0x0.c");
}
