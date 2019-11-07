//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c",
        "west", "/lib/tutorial/eledhel/southern-city/southwest-tower/2x2.c");
    addBuilding("/lib/environment/buildings/military/city-wall.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");

    addDecorator("inner east-west wall");

    addExit("north", "/lib/tutorial/eledhel/southern-city/2x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/3x1.c");
}
