//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/gem-store.c",
        "east", "/areas/eledhel/southern-city/13x7.c");
    addBuilding("/lib/environment/buildings/shops/glass-blower.c",
        "west", "/areas/eledhel/southern-city/11x7.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/areas/eledhel/southern-city/12x8.c");
    addExit("south", "/areas/eledhel/southern-city/12x6.c");
}
