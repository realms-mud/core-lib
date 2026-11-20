//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("village road T-north");
    setShortDescription("The last standing waymarker");
    addItem("/lib/environment/items/objects/broken-cart.c", "south");
    addItem("/lib/environment/items/objects/milestone.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addClue("broken cart", "last-waymarker", "inspectBrokenCart",
        "The wheel failed at its hub. The carter unbuckled "
        "the harness and removed a wooden slat to use as a crutch.");
    addExit("east", "/areas/minlach/surrounding/2x4.c");
    addExit("west", "/areas/minlach/surrounding/0x4.c");
    addExit("north", "/areas/minlach/surrounding/1x5.c");
}
