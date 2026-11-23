//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addObject("/areas/eledhel/southern-city/characters/docks/"
        "cira.c");
    setTerrain("/lib/environment/terrain/pier.c");
    addFeature("/lib/environment/features/water/ocean.c", "east");
    addBuildingWithDoor("/lib/environment/buildings/trades/shipYard.c",
        "north", "/areas/eledhel/southern-city/shipyard/1x0.c",
        "/lib/environment/doors/plank-door.c");
    addFeature("/lib/environment/features/water/ocean.c", "south");

    addDecorator("dock");
    addExit("west", "/areas/eledhel/southern-city/21x4.c");
    addExit("east", "/areas/eledhel/southern-city/23x4.c");
}
