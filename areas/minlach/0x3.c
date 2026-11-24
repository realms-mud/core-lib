//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("village road T-east");
    setShortDescription("The militia drill yard");
    addItem("/lib/environment/items/military/weapon-rack.c", "west");
    addItem("/lib/environment/items/military/training-dummy.c", "east");
    addItem("/lib/environment/items/military/drill-field-marker.c", "south");
    addItem("/lib/environment/items/objects/notice-board.c", "north");
    addItem("/areas/minlach/items/road-survey-board.c", "northeast");
    addObject("/areas/minlach/characters/bren/bren.c");
    addObject("/areas/minlach/characters/basil/basil.c");
    addObject("/areas/minlach/characters/renveth/renveth.c");
    addClue("watch signals", "place-at-the-wall", "readWatchSignals",
        "The slate identifies the alarm signals and a sheltered "
        "assembly point away from the open gate.");
    addClue("supply roster", "place-at-the-wall", "checkSupplyRoster",
        "The roster separates a guarded delivery, a latch repair, "
        "and an unconfirmed road rumor. They need different responses.");
    addInvestigationClue("road survey board",
        "/areas/minlach/quests/road-measure.c", "checkTownWatch",
        "The watch roster shows which streets and gates are covered. "
        "The local watch can coordinate with Basil, but its people "
        "remain under Minlach's command.");
    addExit("south", "/areas/minlach/0x2.c");
    addBuildingWithDoor("/lib/environment/buildings/civic/archive.c",
        "north", "/areas/minlach/0x4.c",
        "/lib/environment/doors/plank-door.c");
    addExit("east", "/areas/minlach/1x3.c");
}
