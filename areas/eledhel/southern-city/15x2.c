//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/homes/large-limestone-house.c",
        "north");
    addBuilding("/lib/environment/buildings/military/military-training-ground.c",
        "south");
    addBuilding("/lib/environment/buildings/military/city-wall.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");

    addExit("west", "/areas/eledhel/southern-city/14x2.c");
    addExit("east", "/areas/eledhel/southern-city/16x2.c");
}
