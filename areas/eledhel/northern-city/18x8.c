//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The public library stands beside the avenue");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "east");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "west");
    addBuildingWithDoor(
        "/lib/environment/buildings/civic/library-large.c", "north",
        "/areas/eledhel/northern-city/library/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addDecorator("east-west road");
    addExit("west", "/areas/eledhel/northern-city/17x8.c");
    addExit("east", "/areas/eledhel/northern-city/19x8.c");
}
