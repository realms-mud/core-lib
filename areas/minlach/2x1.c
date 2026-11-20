//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    addDecorator("keep interior west entry alcove");
    setShortDescription("Roven's common room");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addItem("/lib/environment/items/furniture/long-table.c", "south");
    addItem("/lib/environment/items/furniture/counter.c", "east");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addClue("inn witness account", "constables-witness",
        "readInnWitnessAccount", "The inn's witness places the alarm "
        "after the departure already recorded at the gate.");
    addClue("travelers account", "warm-room", "readTravelersAccount",
        "The household needs two nights while its boat is repaired. "
        "Its members can mend cloth and keep simple cargo tallies.");
    addClue("household work board", "warm-room", "readHouseholdWorkBoard",
        "The work board offers paid mending and tally work at a "
        "stated rate. Neither task requires dangerous travel.");
    addItem("/lib/environment/items/lighting/fireplace.c", "north");
    addObject("/areas/minlach/characters/roven/roven.c");

    addExitWithDoor("west", "/areas/minlach/1x1.c",
        "/lib/environment/doors/plank-door.c");
}
