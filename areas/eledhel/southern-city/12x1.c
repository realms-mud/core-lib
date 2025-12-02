//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/gate-house.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");

    addDecorator("south gate house");
    addExitWithDoor("north", "/areas/eledhel/southern-city/12x2.c",
        "/lib/environment/doors/portcullis.c");
    addExitWithDoor("south", "/areas/eledhel/southern-city/12x0.c",
        "/lib/environment/doors/portcullis.c");
}
