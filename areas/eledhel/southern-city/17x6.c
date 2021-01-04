//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/armorer.c",
        "east", "/areas/eledhel/southern-city/18x6.c");

    addExit("north", "/areas/eledhel/southern-city/17x7.c");
    addExit("south", "/areas/eledhel/southern-city/17x5.c");
}
