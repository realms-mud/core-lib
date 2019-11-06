//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/civic/university-building.c",
        "north", "/lib/tutorial/eledhel/southern-city/university/15x0.c");

    addExit("east", "/lib/tutorial/eledhel/southern-city/5x5.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/3x5.c");
}
