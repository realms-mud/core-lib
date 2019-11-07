//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");

    addExit("north", "/lib/tutorial/eledhel/southern-city/9x9.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/9x7.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/8x8.c");
}
