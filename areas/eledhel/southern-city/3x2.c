//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/archery-range.c",
        "south");
    addBuilding("/lib/environment/buildings/military/city-wall.c", "south");
    addBuilding("/lib/environment/buildings/homes/manor.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");

    addExit("west", "/areas/eledhel/southern-city/2x2.c");
    addExit("east", "/areas/eledhel/southern-city/4x2.c");
}
