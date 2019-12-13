//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/tailor.c",
        "east", "/lib/tutorial/eledhel/central-city/tailor/0x1.c");

    addExit("north", "/lib/tutorial/eledhel/central-city/14x2.c");
    addExit("south", "/lib/tutorial/eledhel/central-city/14x0.c");
}
