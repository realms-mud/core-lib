//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("village road intersection");
    setShortDescription("The old relay-road junction");
    addItem("/lib/environment/items/objects/milestone.c", "north");
    addItem("/lib/environment/items/records/cargo-slate.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addClue("relay marker", "watchtowers-names", "readRelayMarker",
        "The marker names a coastal watch relay, maintained "
        "from a common repair fund. It makes no claim to royal ownership.");
    addClue("courier receipt", "couriers-packet", "readCourierReceipt",
        "The signed receipt sends the numbered packet to Minlach's "
        "archive. A warehouse is not named on this original route.");
    addExit("east", "/areas/minlach/surrounding/3x4.c");
    addExit("south", "/areas/minlach/surrounding/2x3.c");
    addExit("west", "/areas/minlach/surrounding/1x4.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/disused-water-mill.c",
        "north", "/areas/minlach/surrounding/2x5.c",
        "/lib/environment/doors/plank-door.c");
}
