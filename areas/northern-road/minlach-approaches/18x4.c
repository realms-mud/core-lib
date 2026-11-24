//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "north");
    addItem("/lib/environment/items/objects/signPost.c", "southwest");
    addDecorator("village road T-south");

    addExit("west", "/areas/northern-road/minlach-approaches/17x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/19x4.c");
    addExit("south", "/areas/northern-road/minlach-approaches/18x5.c");
}
