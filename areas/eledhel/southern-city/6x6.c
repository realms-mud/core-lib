//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/book-vendor.c",
        "east", "/areas/eledhel/southern-city/7x6.c");

    addExit("north", "/areas/eledhel/southern-city/6x7.c");
    addExit("south", "/areas/eledhel/southern-city/6x5.c");
}
