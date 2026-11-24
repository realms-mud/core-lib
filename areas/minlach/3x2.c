//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    addDecorator("keep interior north-west corner hallway");
    setShortDescription("The quay warehouse");
    addItem("/lib/environment/items/marine/barrel.c", "north");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addItem("/lib/environment/items/records/sealed-packet.c", "east");
    addItem("/lib/environment/items/objects/broken-latch.c", "west");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addClue("cargo manifest", "short-weight-cargo", "checkCargoManifest",
        "The loaded weight includes packing brine. The receiving "
        "account did not distinguish drained barrels from full ones.");
    addClue("warehouse latch", "constables-witness", "inspectWarehouseLatch",
        "The latch broke outward; fresh splinters lie in the yard. "
        "That is not consistent with the reported forced entry.");
    addClue("packet seal", "couriers-packet", "inspectPacketSeal",
        "The packet seal is intact. Only its outer routing slip "
        "has been replaced with a warehouse destination.");
    addInvestigationClue("stores ledger",
        "/areas/minlach/quests/road-measure.c", "checkAvailableStores",
        "The account separates Minlach's reserve grain, lamp oil, and "
        "repair stock from goods already promised to local households.");
    addExitWithDoor("west", "/areas/minlach/2x2.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("north", "/areas/minlach/3x3.c",
        "/lib/environment/doors/plank-door.c");
}
