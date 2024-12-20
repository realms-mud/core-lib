//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/furrier.c",
        "east", "/areas/eledhel/southern-city/13x0.c");
    addBuilding("/lib/environment/buildings/shops/tavern.c",
        "west", "/areas/eledhel/southern-city/11x0.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/areas/eledhel/central-city/12x1.c");
    addExit("south", "/areas/eledhel/southern-city/12x9.c");
}
