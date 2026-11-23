//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A small inn marks the end of the east lane");
    addObject("/areas/eledhel/central-city/characters/inn-supplier.c");
    addBuilding("/lib/environment/buildings/shops/inn.c",
        "east");

    addExit("west", "/areas/eledhel/central-city/19x2.c");
    addExit("south", "/areas/eledhel/central-city/20x1.c");
}
