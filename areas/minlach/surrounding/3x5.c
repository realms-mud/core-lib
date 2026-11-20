//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-mountain.c");
    addDecorator("hill quarry T-east");
    setShortDescription("The stoneworkers' yard");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    addItem("/lib/environment/items/crafts/ore-cart.c", "south");
    addItem("/lib/environment/items/objects/notice-board.c", "east");
    addObject("/areas/minlach/characters/harl/harl.c");
    addExit("south", "/areas/minlach/surrounding/3x4.c");
    addExit("east", "/areas/minlach/surrounding/4x5.c");
    addExit("north", "/areas/minlach/surrounding/3x6.c");
}
