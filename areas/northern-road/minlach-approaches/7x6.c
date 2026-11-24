//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/water/stream.c", "north");
    addFeature("/lib/environment/features/agriculture/threshing-floor.c",
        "south");
    addItem("/lib/environment/items/crafts/grain-bin.c", "west");
    addItem("/lib/environment/items/objects/hand-cart.c", "east");
    addDecorator("village road corner NW");

    addObject(
        "/areas/northern-road/minlach-approaches/characters/mera-vell.c");
    addExit("west", "/areas/northern-road/minlach-approaches/6x6.c");
    addExit("north", "/areas/northern-road/minlach-approaches/7x5.c");
}
