//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/gate-house.c");
    addItem("/lib/environment/items/lighting/sconce.c", "west");
    addItem("/lib/environment/items/lighting/sconce.c", "east");

    addDecorator("south gate house");
    addExitWithDoor("north", "/lib/tutorial/eledhel/southern-city/12x2.c",
        "/lib/environment/doors/portcullis.c");
    addExitWithDoor("south", "/lib/tutorial/eledhel/southern-city/12x0.c",
        "/lib/environment/doors/portcullis.c");
}
