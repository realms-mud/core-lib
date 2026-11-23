//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "north");
    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "south");
    addItem("/lib/environment/items/objects/hand-cart.c", "east");

    addDecorator("village road T-north");

    addExit("north", "/areas/northern-road/north-gate/market-gardens/3x3.c");
    addExit("east", "/areas/northern-road/north-gate/market-gardens/4x4.c");
    addExit("west", "/areas/northern-road/north-gate/market-gardens/2x4.c");
}
