//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/dyer.c",
        "east", "/lib/tutorial/eledhel/southern-city/13x8.c");
    addBuilding("/lib/environment/buildings/shops/potter.c",
        "west", "/lib/tutorial/eledhel/southern-city/11x8.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/lib/tutorial/eledhel/southern-city/12x9.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/12x7.c");
}
