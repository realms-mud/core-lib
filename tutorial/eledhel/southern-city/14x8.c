//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/blacksmith.c",
        "east", "/lib/tutorial/eledhel/southern-city/axe-and-hammer/0x1.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/14x9.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/14x7.c");
}
