//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addItem("/lib/environment/items/lighting/window.c", "east");

    addDecorator("2x1 building 1x0");
    addExitWithDoor("west", "/lib/tutorial/eledhel/southern-city/21x8.c");
}
