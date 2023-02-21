//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/swordsmith.c",
        "west", "/areas/eledhel/southern-city/swordsmith/2x1.c");
    addBuilding("/lib/environment/buildings/shops/ship-wright.c",
        "east", "/areas/eledhel/southern-city/21x8.c");

    addExit("north", "/areas/eledhel/southern-city/20x9.c");
    addExit("south", "/areas/eledhel/southern-city/20x7.c");
}
