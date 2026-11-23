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
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/plants/common-pulse-rows.c",
        "north");
    addItem("/lib/environment/items/objects/wooden-fence.c", "west");

    addDecorator("village road T-east");

    addExit("north", "/areas/northern-road/north-gate/market-gardens/0x1.c");
    addExit("east", "/areas/northern-road/north-gate/market-gardens/1x2.c");
    addExit("south", "/areas/northern-road/north-gate/market-gardens/0x3.c");
}
