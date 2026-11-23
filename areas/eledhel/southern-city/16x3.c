//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addObject("/areas/eledhel/southern-city/characters/streets/"
        "arel.c");
    setTerrain("/lib/environment/terrain/city.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/inn.c",
        "east", "/areas/eledhel/southern-city/inn/0x1.c",
        "/lib/environment/doors/plank-door.c");
    addBuilding("/lib/environment/buildings/homes/large-limestone-house.c",
        "west");

    addExit("north", "/areas/eledhel/southern-city/16x4.c");
    addExit("south", "/areas/eledhel/southern-city/16x2.c");
}
