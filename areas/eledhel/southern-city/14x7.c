//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addObject("/areas/eledhel/southern-city/characters/streets/"
        "soren.c");
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/trades/smelter.c", "east");

    addExit("north", "/areas/eledhel/southern-city/14x8.c");
    addExit("south", "/areas/eledhel/southern-city/14x6.c");
}
