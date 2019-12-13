//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/weaponsmith.c",
        "east", "/lib/tutorial/eledhel/central-city/maces/0x1.c");
    addBuilding("/lib/environment/buildings/shops/leatherworking-shop.c",
        "west", "/lib/tutorial/eledhel/central-city/leather/2x1.c");

    addExit("north", "/lib/tutorial/eledhel/central-city/17x1.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/17x9.c");
}
