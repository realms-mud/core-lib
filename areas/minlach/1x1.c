//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("village square");
    setShortDescription("Minlach market crossing");
    addItem("/lib/environment/items/objects/market-stall.c", "east");
    addItem("/lib/environment/items/objects/merchant-scales.c", "east");
    addItem("/lib/environment/items/objects/sack-pile.c", "west");
    addItem("/lib/environment/items/objects/packing-crate.c", "west");
    addClue("market scales", "short-weight-cargo", "checkMarketScales",
        "The marked test weight balances correctly. The fish barrels "
        "nearby show dried brine below their split packing hoops.");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addObject("/areas/minlach/characters/sella/sella.c");

    addExit("south", "/areas/minlach/1x0.c");
    addExit("north", "/areas/minlach/1x2.c");
    addExit("west", "/areas/minlach/0x1.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/inn.c", "east",
        "/areas/minlach/2x1.c", "/lib/environment/doors/plank-door.c");
}
