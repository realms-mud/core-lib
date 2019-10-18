//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/wainwright.c", "north");

    addExit("west", "/lib/tutorial/eledhel/southern-city/13x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/15x2.c");
}
