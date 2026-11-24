//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/plants/common-root-beds.c",
        "south");
    addItem("/lib/environment/items/objects/broken-cart.c", "north");
    addItem("/lib/environment/items/objects/hand-cart.c", "west");
    addDecorator("village east-west road");

    addExit("west", "/areas/northern-road/minlach-approaches/14x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/16x4.c");
}
