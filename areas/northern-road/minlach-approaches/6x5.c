//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/water/stream.c", "south");
    addItem("/lib/environment/items/crafts/flour-sack.c", "north");
    addItem("/lib/environment/items/objects/water-trough.c", "west");
    addDecorator("village road T-south");

    addExit("west", "/areas/northern-road/minlach-approaches/5x5.c");
    addExit("east", "/areas/northern-road/minlach-approaches/7x5.c");
    addExit("south", "/areas/northern-road/minlach-approaches/6x6.c");
}
