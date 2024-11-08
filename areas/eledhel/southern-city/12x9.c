//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/weaver.c",
        "east", "/areas/eledhel/southern-city/13x9.c");
    addBuilding("/lib/environment/buildings/shops/carpenter.c",
        "west", "/areas/eledhel/southern-city/11x9.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/areas/eledhel/central-city/12x0.c");
    addExit("south", "/areas/eledhel/southern-city/12x8.c");
}
