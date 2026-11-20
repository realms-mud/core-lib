//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("village road intersection");
    setShortDescription("The net-mending yard");
    addItem("/lib/environment/items/marine/torn-fishing-net.c", "east");
    addItem("/lib/environment/items/marine/coiled-rope.c", "south");
    addFeature("/lib/environment/features/stairs/straight-staircase.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addClue("torn net", "net-for-winter", "inspectTornNet",
        "The damage follows worn knots and frayed lashings. "
        "The strands have not been cleanly cut with a blade.");
    addExit("south", "/areas/minlach/1x2.c");
    addExit("west", "/areas/minlach/0x3.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/craft-workshop.c",
        "east", "/areas/minlach/2x3.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/minlach/1x4.c");
    addExit("down", "/areas/minlach/shore/0x0.c");
}
