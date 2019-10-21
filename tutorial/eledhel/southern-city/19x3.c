//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/inn.c",
        "west", "/lib/tutorial/eledhel/southern-city/inn/0x1.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/19x4.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/19x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/20x3.c");
}
