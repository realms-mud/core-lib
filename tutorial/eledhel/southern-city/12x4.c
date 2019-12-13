//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/wainwright.c",
        "east", "/lib/tutorial/eledhel/southern-city/wainwright/0x1.c");
    addBuilding("/lib/environment/buildings/shops/herbalist.c",
        "west", "/lib/tutorial/eledhel/southern-city/11x4.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/lib/tutorial/eledhel/southern-city/12x5.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/12x3.c");
}
