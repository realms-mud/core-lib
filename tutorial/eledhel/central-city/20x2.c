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
        "east", "/lib/tutorial/eledhel/central-city/inn/0x4.c");

    addExit("west", "/lib/tutorial/eledhel/central-city/19x2.c");
    addExit("south", "/lib/tutorial/eledhel/central-city/20x1.c");
}
