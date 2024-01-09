//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("east", "/areas/eledhel/southern-city/10x5.c");
    addExit("west", "/areas/eledhel/southern-city/8x5.c");
    addExit("north", "/areas/eledhel/southern-city/9x6.c");
    addExit("south", "/areas/eledhel/southern-city/9x4.c");
}
