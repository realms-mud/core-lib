//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/gate-house.c",
        "south", "/lib/tutorial/eledhel/southern-city/12x1.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/12x3.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/11x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/13x2.c");
}
