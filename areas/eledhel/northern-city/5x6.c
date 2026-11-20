//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The Arena Park crossroads");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    addDecorator("road intersection");
    addBuildingWithDoor("/lib/environment/buildings/guilds/phaedra.c",
        "south", "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c",
        "/lib/environment/doors/plank-door.c");
    addExit("north", "/areas/eledhel/northern-city/5x7.c");
    addExit("east", "/areas/eledhel/northern-city/6x6.c");
    addExit("west", "/areas/eledhel/northern-city/4x6.c");
}
