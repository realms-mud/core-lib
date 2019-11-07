//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/civic/university-building.c",
        "north", "/lib/tutorial/eledhel/southern-city/university/10x0.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");

    addExit("east", "/lib/tutorial/eledhel/southern-city/4x5.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/2x5.c");
}
