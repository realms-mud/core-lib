//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/plants/common-grain-strips.c",
        "south");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "west");
    addItem("/lib/environment/items/objects/signPost.c", "northwest");
    addDecorator("village road T-north");

    addExit("west", "/areas/northern-road/minlach-approaches/1x4.c");
    addExit("east", "/areas/northern-road/minlach-approaches/3x4.c");
    addExit("north", "/areas/northern-road/minlach-approaches/2x3.c");
}
