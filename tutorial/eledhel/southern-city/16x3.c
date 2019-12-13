//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/inn.c",
        "east", "/lib/tutorial/eledhel/southern-city/inn/0x0.c");
    addBuilding("/lib/environment/buildings/homes/large-limestone-house.c",
        "west");

    addExit("north", "/lib/tutorial/eledhel/southern-city/16x4.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/16x2.c");
}
