//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior east-west hallway south entry");
    setShortDescription("The harbor refuge");
    addItem("/lib/environment/items/furniture/bed.c", "north");
    addItem("/lib/environment/items/marine/barrel-of-water.c", "east");
    addItem("/lib/environment/items/lighting/fireplace.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addExitWithDoor("west", "/areas/minlach/1x4.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("south", "/areas/minlach/2x3.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("east", "/areas/minlach/3x4.c",
        "/lib/environment/doors/plank-door.c");
}
