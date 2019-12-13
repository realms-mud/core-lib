//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/guilds/scion-of-dhuras.c",
        "west", "/lib/tutorial/eledhel/southern-city/scion-of-dhuras/4x3.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/9x4.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/9x2.c");
}
