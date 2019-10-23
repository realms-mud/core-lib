//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/homes/palace.c",
        "east", "/lib/tutorial/eledhel/palace/0x4.c");

    addExit("west", "/lib/tutorial/eledhel/central-city/13x5.c");
}
