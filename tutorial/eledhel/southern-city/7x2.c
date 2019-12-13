//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/guilds/scion-of-dhuras.c", "north");
    addBuilding("/lib/environment/buildings/military/military-training-ground.c",
        "south", "/lib/tutorial/eledhel/southern-city/7x1.c");
    addBuilding("/lib/environment/buildings/military/city-wall.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/entry-path.c", "south");

    addExit("west", "/lib/tutorial/eledhel/southern-city/6x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/8x2.c");
}
