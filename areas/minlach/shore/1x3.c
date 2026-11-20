//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/sandy-shoreline.c");
    addDecorator("sandy shore");
    setShortDescription("The cove's landing beach");
    addItem("/lib/environment/items/marine/boat-ramp.c", "east");
    addItem("/lib/environment/items/marine/coiled-rope.c", "west");
    addExit("west", "/areas/minlach/shore/0x3.c");
    addExit("east", "/areas/minlach/shore/2x3.c");
}
