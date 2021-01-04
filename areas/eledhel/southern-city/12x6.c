//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuilding("/lib/environment/buildings/shops/jeweler.c",
        "east", "/areas/eledhel/southern-city/13x6.c");
    addBuilding("/lib/environment/buildings/shops/engraver.c",
        "west", "/areas/eledhel/southern-city/11x6.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");

    addExit("north", "/areas/eledhel/southern-city/12x7.c");
    addExit("south", "/areas/eledhel/southern-city/12x5.c");
}
