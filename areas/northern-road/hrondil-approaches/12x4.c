//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/water/field-drain.c", "south");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "southwest");
    addItem("/lib/environment/items/objects/signPost.c", "northwest");
    addItem("/lib/environment/items/objects/hand-cart.c", "southeast");
    addObject("/areas/northern-road/hrondil-approaches/characters/crofter.c");

    addDecorator("village road T-north");

    addExit("north", "/areas/hrondil/approach/0x0.c");
    addExit("east", "/areas/northern-road/hrondil-approaches/13x4.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/11x4.c");
}
