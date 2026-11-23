//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A crossing between the library and Morleth's Stone");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addDecorator("road intersection");
    addExit("west", "/areas/eledhel/northern-city/19x8.c");
    addExit("east", "/areas/eledhel/northern-city/21x8.c");
    addExit("south", "/areas/eledhel/northern-city/20x7.c");
}
