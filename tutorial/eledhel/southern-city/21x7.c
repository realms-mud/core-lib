//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/trades/shipYard.c",
        "east", "/lib/tutorial/eledhel/southern-city/shipyard/0x1.c");

    addExit("west", "/lib/tutorial/eledhel/southern-city/20x7.c");
}
