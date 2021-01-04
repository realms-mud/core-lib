//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/trades/market.c",
        "east", "/areas/eledhel/southern-city/market/0x1.c");

    addExit("west", "/areas/eledhel/southern-city/18x5.c");
    addExit("south", "/areas/eledhel/southern-city/19x4.c");
    addExit("north", "/areas/eledhel/southern-city/19x6.c");
}
