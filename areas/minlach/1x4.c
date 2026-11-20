//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addDecorator("rocky shore");
    setShortDescription("Minlach's harbor beacon");
    addItem("/lib/environment/items/military/beacon.c", "north");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "northwest");
    addFeature("/lib/environment/features/landforms/promontory.c", "west");
    addObject("/areas/minlach/characters/neris/neris.c");
    addClue("beacon log", "false-harbor-light", "readBeaconLog",
        "Two tenders signed the light's uninterrupted watch. "
        "A light below this platform could not have been its signal.");
    addExit("south", "/areas/minlach/1x3.c");
    addExitWithDoor("west", "/areas/minlach/0x4.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor("/lib/environment/buildings/civic/harbor-refuge.c",
        "east", "/areas/minlach/2x4.c",
        "/lib/environment/doors/plank-door.c");
    addExit("northwest", "/areas/minlach/shore/2x0.c");
}
