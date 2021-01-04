//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/wall-tower.c",
        "west", "/areas/eledhel/southern-city/west-wall/2x8.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");

    addDecorator("inner north-south wall");
    addExit("east", "/areas/eledhel/southern-city/2x5.c");
    addExit("north", "/areas/eledhel/southern-city/1x6.c");
    addExit("south", "/areas/eledhel/southern-city/1x4.c");
}
