//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/brewer.c",
        "east", "/areas/eledhel/central-city/brewery/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor("/lib/environment/buildings/civic/theater.c",
        "west", "/areas/eledhel/central-city/theater/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addFeature("/lib/environment/features/paths/cobblestone-road.c", "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c", "south");
    setShortDescription("A brewery and small theater face the same block");
    addObject("/areas/eledhel/central-city/characters/theater-handbill-runner.c");

    addExit("north", "/areas/eledhel/central-city/12x2.c");
    addExit("south", "/areas/eledhel/central-city/12x0.c");
}
