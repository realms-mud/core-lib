//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/leatherworking-shop.c",
        "east", "/lib/tutorial/eledhel/central-city/leather/0x1.c");

    addExit("north", "/lib/tutorial/eledhel/central-city/14x1.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/14x9.c");
}
