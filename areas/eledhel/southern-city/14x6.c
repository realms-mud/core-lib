//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addObject("/areas/eledhel/southern-city/characters/streets/"
        "rinan.c");
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/trades/smelter.c",
        "east", "/areas/eledhel/southern-city/smelter/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/southern-city/14x7.c");
    addExit("south", "/areas/eledhel/southern-city/14x5.c");
}
