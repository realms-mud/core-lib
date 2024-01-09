//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c", "south");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c", "north");
    addFeature("/lib/environment/features/water/ocean.c", "east");
    addBuilding("/lib/environment/buildings/trades/market.c", "north");

    addDecorator("dock");
    addExit("west", "/areas/eledhel/southern-city/19x4.c");
    addExit("east", "/areas/eledhel/southern-city/21x4.c");
}
