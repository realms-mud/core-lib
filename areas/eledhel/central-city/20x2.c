//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/inn.c",
        "east", "/areas/eledhel/central-city/inn/0x4.c");

    addExit("west", "/areas/eledhel/central-city/19x2.c");
    addExit("south", "/areas/eledhel/central-city/20x1.c");
}
