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
        "west", "/lib/tutorial/eledhel/central-city/maces/2x1.c");
    addBuilding("/lib/environment/buildings/shops/general-shop.c",
        "east", "/lib/tutorial/eledhel/central-city/21x0.c");

    addExit("north", "/lib/tutorial/eledhel/central-city/20x1.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/20x9.c");
}
