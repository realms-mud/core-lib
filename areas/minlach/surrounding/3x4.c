//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addDecorator("hill quarry T-west");
    setShortDescription("The quarry settling lane");
    addFeature("/lib/environment/features/water/silted-sluice.c", "east");
    addItem("/lib/environment/items/crafts/ore-cart.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addClue("settling ditch", "roots-by-the-stream", "inspectSettlingDitch",
        "Fine quarry waste blocks the settling channel. Runoff "
        "has cut a bypass into the garden's downstream supply.");
    addExit("south", "/areas/minlach/surrounding/3x3.c");
    addExit("north", "/areas/minlach/surrounding/3x5.c");
    addExit("west", "/areas/minlach/surrounding/2x4.c");
}
