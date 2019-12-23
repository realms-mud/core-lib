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
        "west", "/areas/eledhel/central-city/maces/2x1.c");
    addBuilding("/lib/environment/buildings/shops/general-shop.c",
        "east", "/areas/eledhel/central-city/21x0.c");

    addExit("north", "/areas/eledhel/central-city/20x1.c");
    addExit("south", "/areas/eledhel/southern-city/20x9.c");
}
