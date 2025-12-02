//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/limestone-interior-shop.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "south");

    addExit("north", "/areas/eledhel/southern-city/swordsmith/1x1.c");
    addExitWithDoor("east", "/areas/eledhel/southern-city/swordsmith/2x0.c");
}
