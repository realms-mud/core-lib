//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/mage-shop.c",
        "east", "/areas/eledhel/southern-city/7x7.c");

    addExit("north", "/areas/eledhel/southern-city/6x8.c");
    addExit("south", "/areas/eledhel/southern-city/6x6.c");
}
