//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/water/stream.c", "south");
    addItem("/lib/environment/items/objects/well.c", "east");
    addDecorator("village road T-west");

    addObject(
        "/areas/northern-road/minlach-approaches/characters/renn-vell.c");
    addExit("west", "/areas/northern-road/minlach-approaches/6x5.c");
    addExit("north", "/areas/northern-road/minlach-approaches/7x4.c");
    addExit("south", "/areas/northern-road/minlach-approaches/7x6.c");
}
