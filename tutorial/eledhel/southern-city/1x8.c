//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/military/tall-stone-wall.c",
        "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");

    addDecorator("inner north-south wall");

    addExit("north", "/lib/tutorial/eledhel/southern-city/1x9.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/1x7.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/2x8.c");
}
