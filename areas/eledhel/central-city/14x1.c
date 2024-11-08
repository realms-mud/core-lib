//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/tailor.c",
        "east", "/areas/eledhel/central-city/tailor/0x1.c");

    addExit("north", "/areas/eledhel/central-city/14x2.c");
    addExit("south", "/areas/eledhel/central-city/14x0.c");
}
