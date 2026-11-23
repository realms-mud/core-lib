//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "south");

    addDecorator("village road T-south");

    addExit("east", "/areas/northern-road/north-gate/market-gardens/2x0.c");
    addExit("south", "/areas/northern-road/north-gate/market-gardens/1x1.c");
    addExit("west", "/areas/northern-road/north-gate/market-gardens/0x0.c");
}
