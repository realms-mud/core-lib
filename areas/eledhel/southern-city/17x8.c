//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/blacksmith.c", "west");
    addBuilding("/lib/environment/buildings/shops/swordsmith.c",
        "east", "/areas/eledhel/southern-city/swordsmith/0x1.c");

    addExit("north", "/areas/eledhel/southern-city/17x9.c");
    addExit("south", "/areas/eledhel/southern-city/17x7.c");
}
