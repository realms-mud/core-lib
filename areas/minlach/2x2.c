//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("village road T-north");
    setShortDescription("The factor's quay");
    addItem("/lib/environment/items/records/cargo-slate.c", "north");
    addItem("/lib/environment/items/marine/barrel.c", "east");
    addItem("/lib/environment/items/marine/dock.c", "west");
    addClue("dock tally", "short-weight-cargo", "checkDockTally",
        "The crew recorded a split cart hoop and leaking barrels "
        "before unloading. Its signed account explains the lost brine.");
    addObject("/areas/minlach/characters/fennel/fennel.c");

    addExit("west", "/areas/minlach/1x2.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/warehouse.c",
        "east", "/areas/minlach/3x2.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/craft-workshop.c",
        "north", "/areas/minlach/2x3.c",
        "/lib/environment/doors/plank-door.c");
}
