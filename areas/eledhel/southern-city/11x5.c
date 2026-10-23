//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/herbalist.c", "south");
    addBuilding(
        "/lib/environment/buildings/guilds/monk-training-hall.c",
        "northeast",
        "/areas/eledhel/southern-city/monk-hall/0x0.c");

    addExit("east", "/areas/eledhel/southern-city/12x5.c");
    addExit("west", "/areas/eledhel/southern-city/10x5.c");
}
