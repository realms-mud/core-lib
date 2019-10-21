//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/trades/smelter.c",
        "east", "/lib/tutorial/eledhel/southern-city/smelter/0x0.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/14x7.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/14x5.c");
}
