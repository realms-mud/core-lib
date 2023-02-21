//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/military-training-ground.c",
        "southwest");
    addBuilding("/lib/environment/buildings/military/city-wall.c", "south");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c", "southeast");
    addFeature("/lib/environment/features/water/ocean.c", "east");
    addItem("/lib/environment/items/marine/pier.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/areas/eledhel/southern-city/19x3.c");
    addExit("south", "/areas/eledhel/southern-city/19x1.c");
    addExit("west", "/areas/eledhel/southern-city/18x2.c");
    addExit("east", "/areas/eledhel/southern-city/20x2.c");
}
