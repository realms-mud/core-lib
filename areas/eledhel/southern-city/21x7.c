//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/shipYard.c",
        "east", "/areas/eledhel/southern-city/shipyard/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("west", "/areas/eledhel/southern-city/20x7.c");
}
