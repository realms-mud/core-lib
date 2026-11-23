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
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/plants/common-kitchen-garden.c",
        "west");
    addItem("/lib/environment/items/objects/market-stall.c", "south");
    addObject(
        "/areas/northern-road/north-gate/market-gardens/characters/aelwen.c");

    addDecorator("village road intersection");

    addExit("north", "/areas/northern-road/north-gate/market-gardens/2x1.c");
    addExit("east", "/areas/northern-road/north-gate/market-gardens/3x2.c");
    addExit("south", "/areas/northern-road/north-gate/market-gardens/2x3.c");
    addExit("west", "/areas/northern-road/north-gate/market-gardens/1x2.c");
}
