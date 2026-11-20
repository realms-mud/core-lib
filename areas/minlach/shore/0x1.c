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
    setShortDescription("The working shore path");
    addItem("/lib/environment/items/marine/boat-ramp.c", "east");
    addItem("/lib/environment/items/objects/milestone.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/minlach/shore/0x0.c");
    addExit("north", "/areas/minlach/shore/0x2.c");
}
