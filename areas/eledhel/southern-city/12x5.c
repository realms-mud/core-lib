//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addBuilding("/lib/environment/buildings/religious/church-of-ilyrth.c",
        "east", "/areas/eledhel/southern-city/church-of-ilyrth/0x3.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");

    addExit("north", "/areas/eledhel/southern-city/12x6.c");
    addExit("south", "/areas/eledhel/southern-city/12x4.c");
    addExit("west", "/areas/eledhel/southern-city/11x5.c");
}
