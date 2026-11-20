//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    addDecorator("keep interior south-west corner hallway");
    setShortDescription("The old mill shelter");
    addItem("/lib/environment/items/furniture/bed.c", "north");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addClue("mill shelter note", "last-waymarker", "readMillShelterNote",
        "The carter names himself and his apprentice. A farm "
        "worker brought them to safety; they need a wagon because "
        "the carter cannot walk home.");
    addExitWithDoor("south", "/areas/minlach/surrounding/2x4.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("west", "/areas/minlach/surrounding/1x5.c",
        "/lib/environment/doors/plank-door.c");
}
