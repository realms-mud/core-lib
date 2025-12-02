//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/inn.c", "south");

    addExit("east", "/areas/eledhel/southern-city/18x5.c");
    addExit("west", "/areas/eledhel/southern-city/16x5.c");
    addExit("north", "/areas/eledhel/southern-city/17x6.c");
}
