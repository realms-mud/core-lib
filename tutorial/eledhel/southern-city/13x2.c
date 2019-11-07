//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/wainwright.c", "north");
    addBuilding("/lib/environment/buildings/military/tall-wall-tower.c",
        "south", "/lib/tutorial/eledhel/southern-city/southeast-gate-tower/4x4.c");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/entry-path.c", "south");

    addExit("west", "/lib/tutorial/eledhel/southern-city/12x2.c");
    addExit("east", "/lib/tutorial/eledhel/southern-city/14x2.c");
}
