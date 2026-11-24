//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/keep.c");
    addFeature("/lib/environment/features/paths/gravel-road.c", "north");
    addFeature("/lib/environment/features/paths/gravel-road.c", "south");
    addItem("/lib/environment/items/military/supply-crate.c", "east");
    addItem("/lib/environment/items/objects/notice-board.c", "west");
    addDecorator("village road intersection");

    addObject(
        "/areas/northern-road/minlach-approaches/characters/cael-reth.c");
    addExit("south", "/areas/northern-road/minlach-approaches/12x3.c");
    addExit("north", "/areas/northern-road/minlach-approaches/12x1.c");
    addExit("east", "/areas/northern-road/minlach-approaches/13x2.c");
}
