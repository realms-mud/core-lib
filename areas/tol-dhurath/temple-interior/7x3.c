//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");

    addExitWithDoor("north",
        "/areas/tol-dhurath/temple-interior/7x4.c");
    addExitWithDoor("south", 
        "/areas/tol-dhurath/temple-exterior/6x7.c");

    addDecorator("ruined interior south gatehouse");
}
