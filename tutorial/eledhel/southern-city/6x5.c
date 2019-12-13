//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");

    addExit("east", "/lib/tutorial/eledhel/southern-city/7x5.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/5x5.c");
    addExit("north", "/lib/tutorial/eledhel/southern-city/6x6.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/6x4.c");
}
