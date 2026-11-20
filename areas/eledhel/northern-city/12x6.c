//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addDecorator("road intersection");

    addExit("west", "/areas/eledhel/northern-city/11x6.c");
    addExit("east", "/areas/eledhel/northern-city/13x6.c");
    addExit("south", "/areas/eledhel/northern-city/12x5.c");
    addExit("north", "/areas/eledhel/northern-city/12x7.c");
}
