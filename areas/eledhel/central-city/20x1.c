//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/weaponsmith.c",
        "west", "/areas/eledhel/central-city/pole-arms/2x1.c");
    addBuilding("/lib/environment/buildings/shops/inn.c",
        "east", "/areas/eledhel/central-city/inn/0x0.c");

    addExit("north", "/areas/eledhel/central-city/20x2.c");
    addExit("south", "/areas/eledhel/central-city/20x0.c");
}
