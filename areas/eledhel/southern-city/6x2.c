//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/military-training-ground.c",
        "south");
    addBuilding("/lib/environment/buildings/military/city-wall.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");

    addExit("west", "/areas/eledhel/southern-city/5x2.c");
    addExit("east", "/areas/eledhel/southern-city/7x2.c");
    addExit("north", "/areas/eledhel/southern-city/6x3.c");
}
