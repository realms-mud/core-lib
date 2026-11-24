//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("village keep gate");
    setShortDescription("Minlach's south gate");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addItem("/lib/environment/items/military/small-barricade.c", "east");
    addItem("/lib/environment/items/marine/harbor-lantern.c", "north");
    addClue("gate statement", "constables-witness", "readGateStatement",
        "The watch recorded the accused traveler leaving before "
        "the warehouse alarm. The ink and witness marks are consistent.");
    addClue("gate inspection", "place-at-the-wall", "checkGateInspection",
        "The inspection board lists a loose latch, not a forced "
        "entry. A repair request has already been recorded.");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");

    addExit("south", "/areas/eledhel/north-road/2x4.c");
    addExit("west", "/areas/northern-road/minlach-approaches/24x4.c");
    addExit("north", "/areas/minlach/1x1.c");
}
