//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/opulent-entry.c");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/lighting/sconce.c", "east");
    addItem("/lib/environment/items/lighting/sconce.c", "west");

    addExitWithDoor("south", 
        "/areas/tol-dhurath/temple-exterior/6x7.c");

    addDecorator("ruined interior south gatehouse");
}
