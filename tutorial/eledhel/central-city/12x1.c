//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/brewer.c",
        "east", "/lib/tutorial/eledhel/southern-city/13x0.c");
    addBuilding("/lib/environment/buildings/civic/theater.c",
        "west");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/lib/tutorial/eledhel/central-city/12x2.c");
    addExit("south", "/lib/tutorial/eledhel/central-city/12x0.c");
}
