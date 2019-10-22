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
        "west", "/lib/tutorial/eledhel/southern-city/weaponsmith/2x1.c");
    addBuilding("/lib/environment/buildings/shops/grocer.c",
        "east", "/lib/tutorial/eledhel/southern-city/21x9.c");

    addExit("south", "/lib/tutorial/eledhel/southern-city/20x8.c");
    addExit("north", "/lib/tutorial/eledhel/central-city/20x0.c");
}
