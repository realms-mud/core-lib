//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/mage-shop.c",
        "east", "/lib/tutorial/eledhel/southern-city/7x7.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/6x8.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/6x6.c");
}
