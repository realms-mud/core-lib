//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-west passage");
    setShortDescription("The supported upper gallery");
    addFeature("/lib/environment/features/ore-veins/iron.c", "east");
    addFeature("/lib/environment/features/caves/timber-supports.c", "north");
    addItem("/lib/environment/items/lighting/lantern.c", "west");
    addClue("upper props", "flooded-workings", "inspectUpperProps",
        "The upper props are sound. The lower timbers have "
        "shifted; pulling them could collapse the closed passage.");
    addExit("south", "/areas/minlach/surrounding/4x5.c");
    addExit("west", "/areas/minlach/surrounding/3x6.c");
}
