//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("village road T-north");
    setShortDescription("Minlach's western watch square");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addItem("/lib/environment/items/objects/notice-board.c", "north");
    addItem("/lib/environment/items/marine/harbor-lantern.c", "east");
    addObject("/areas/minlach/characters/tristan/tristan.c");

    addExit("east", "/areas/minlach/1x1.c");
    addExit("north", "/areas/minlach/0x2.c");
    addExit("west", "/areas/minlach/surrounding/4x1.c");
}
