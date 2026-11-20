//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/library.c");
    addDecorator("keep interior south-east corner hallway");
    setShortDescription("Minlach's household archive");
    addItem("/lib/environment/items/furniture/book-shelf.c", "west");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "north");
    addObject("/areas/minlach/characters/orlen/orlen.c");
    addClue("household register", "watchtowers-names",
        "compareHouseholdRegister", "The household book repeats the "
        "tower ledger's workers and common repair fund. These are "
        "local families, not a lost royal line.");
    addClue("courier register", "couriers-packet", "checkCourierRegister",
        "The delivery number belongs to a local repair assessment. "
        "The proper recipient is this archive, not the warehouse.");
    addExitWithDoor("south", "/areas/minlach/0x3.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("east", "/areas/minlach/1x4.c",
        "/lib/environment/doors/plank-door.c");
}
