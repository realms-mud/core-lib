//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c",
        "east", "/areas/eledhel/southern-city/southeast-tower/0x1.c");
    addBuilding("/lib/environment/buildings/military/military-training-ground.c",
        "west");
    addBuilding("/lib/environment/buildings/military/city-wall.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");

    addDecorator("inner east-west wall");
    addExit("north", "/areas/eledhel/southern-city/19x2.c");
    addExit("west", "/areas/eledhel/southern-city/18x1.c");
}
