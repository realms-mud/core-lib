//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c",
        "south", "/lib/tutorial/eledhel/southern-city/southwest-gate-tower/0x4.c");

    addExit("west", "/lib/tutorial/eledhel/southern-city/9x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/11x2.c");
}
