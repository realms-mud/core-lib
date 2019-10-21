//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/trades/foundry.c", "west",
        "/lib/tutorial/eledhel/southern-city/foundry/2x4.c");
    addBuilding("/lib/environment/buildings/shops/armorer.c",
        "east", "/lib/tutorial/eledhel/southern-city/medium-armor/0x1.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/17x8.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/17x6.c");
}
