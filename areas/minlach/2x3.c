//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    addDecorator("keep interior north-south hallway east-west entry");
    setShortDescription("The harbor chandler's workroom");
    addItem("/lib/environment/items/marine/coiled-rope.c", "west");
    addItem("/lib/environment/items/marine/fishing-net.c", "north");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addClue("net repair record", "net-for-winter", "readNetRepairRecord",
        "A replacement line was recommended weeks ago. The household "
        "deferred it when its boat needed repairs.");
    addExitWithDoor("south", "/areas/minlach/2x2.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("west", "/areas/minlach/1x3.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("east", "/areas/minlach/3x3.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("north", "/areas/minlach/2x4.c",
        "/lib/environment/doors/plank-door.c");
}
