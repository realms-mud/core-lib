//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/guilds/scion-of-dhuras.c",
        "south", "/lib/tutorial/eledhel/southern-city/scion-of-dhuras/5x5.c");

    addExit("east", "/lib/tutorial/eledhel/southern-city/9x5.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/7x5.c");
}
