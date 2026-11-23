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
    addFeature("/lib/environment/features/plants/common-kitchen-garden.c",
        "east");

    addDecorator("village road T-south");

    addExit("east", "/areas/northern-road/north-gate/market-gardens/3x0.c");
    addExit("south", "/areas/northern-road/north-gate/market-gardens/2x1.c");
    addExit("west", "/areas/northern-road/north-gate/market-gardens/1x0.c");
}
