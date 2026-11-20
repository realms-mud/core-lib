//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/weaponsmith.c",
        "west");
    addBuilding("/lib/environment/buildings/shops/inn.c",
        "east");

    addExit("north", "/areas/eledhel/central-city/20x2.c");
    addExit("south", "/areas/eledhel/central-city/20x0.c");
}
