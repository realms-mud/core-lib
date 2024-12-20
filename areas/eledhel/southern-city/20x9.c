//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/weaponsmith.c",
        "west", "/areas/eledhel/southern-city/axe-and-hammer/2x1.c");
    addBuilding("/lib/environment/buildings/shops/grocer.c",
        "east", "/areas/eledhel/southern-city/21x9.c");

    addExit("south", "/areas/eledhel/southern-city/20x8.c");
    addExit("north", "/areas/eledhel/central-city/20x0.c");
}
