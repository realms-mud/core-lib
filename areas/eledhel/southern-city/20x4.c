//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addObject("/areas/eledhel/southern-city/characters/docks/"
        "iveron.c");
    setTerrain("/lib/environment/terrain/pier.c");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c", "south");
    addFeature("/lib/environment/features/water/rocky-ocean-shore.c", "north");
    addFeature("/lib/environment/features/water/ocean.c", "east");
    addBuildingWithDoor("/lib/environment/buildings/trades/market.c",
        "north", "/areas/eledhel/southern-city/south-dock-market/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addDecorator("dock");
    addExit("west", "/areas/eledhel/southern-city/19x4.c");
    addExit("east", "/areas/eledhel/southern-city/21x4.c");
}
