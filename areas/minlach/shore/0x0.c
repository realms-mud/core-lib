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
    setShortDescription("The net-yard shore steps");
    addFeature("/lib/environment/features/stairs/straight-staircase.c",
        "east");
    addItem("/lib/environment/items/marine/coiled-rope.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("up", "/areas/minlach/1x3.c");
    addExit("north", "/areas/minlach/shore/0x1.c");
}
