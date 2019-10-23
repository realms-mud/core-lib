//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/weaponsmith.c",
        "east", "/lib/tutorial/eledhel/central-city/pole-arms/2x1.c");
    addBuilding("/lib/environment/buildings/shops/tailor.c",
        "west", "/lib/tutorial/eledhel/central-city/tailor/2x1.c");

    addExit("north", "/lib/tutorial/eledhel/central-city/17x2.c");
    addExit("south", "/lib/tutorial/eledhel/central-city/17x0.c");
}
