//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/trades/smelter.c",
        "east", "/areas/eledhel/southern-city/smelter/0x0.c");

    addExit("north", "/areas/eledhel/southern-city/14x7.c");
    addExit("south", "/areas/eledhel/southern-city/14x5.c");
}
