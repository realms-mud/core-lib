//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/blacksmith.c",
        "east", "/areas/eledhel/southern-city/axe-and-hammer/0x1.c");

    addExit("north", "/areas/eledhel/southern-city/14x9.c");
    addExit("south", "/areas/eledhel/southern-city/14x7.c");
}
