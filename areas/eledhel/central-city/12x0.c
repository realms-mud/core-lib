//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/furrier.c", "east");
    addBuilding("/lib/environment/buildings/shops/tavern.c", "west");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/areas/eledhel/central-city/12x1.c");
    addExit("south", "/areas/eledhel/southern-city/12x9.c");
}
