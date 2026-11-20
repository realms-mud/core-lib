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
    setShortDescription("The lighter quay");
    addItem("/lib/environment/items/marine/rowboat.c", "east");
    addItem("/lib/environment/items/marine/coiled-rope.c", "north");
    addItem("/lib/environment/items/marine/harbor-lantern.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addItem("/lib/environment/items/marine/dock.c", "east");

    addExit("south", "/areas/minlach/1x1.c");
    addExit("west", "/areas/minlach/0x2.c");
    addExit("east", "/areas/minlach/2x2.c");
    addExit("north", "/areas/minlach/1x3.c");
}
