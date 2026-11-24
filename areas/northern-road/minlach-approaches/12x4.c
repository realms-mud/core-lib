//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addItem("/lib/environment/items/military/supply-crate.c", "south");
    addDecorator("village road T-north");

    addExit("west", "/areas/northern-road/minlach-approaches/11x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/13x4.c");
    addExit("north", "/areas/northern-road/minlach-approaches/12x3.c");
}
