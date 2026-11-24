//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/trees/willow-stand.c", "north");
    addFeature("/lib/environment/features/water/stream.c", "west");
    addItem("/lib/environment/items/objects/signPost.c", "northwest");
    addDecorator("village road T-south");

    addExit("west", "/areas/northern-road/minlach-approaches/6x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/8x4.c");
    addExit("south", "/areas/northern-road/minlach-approaches/7x5.c");
}
