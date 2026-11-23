//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Armorers and tailors line this trade street");
    addObject("/areas/eledhel/central-city/characters/tailor-courier.c");
    addBuildingWithDoor(
        "/lib/environment/buildings/shops/weaponsmith.c", "east",
        "/areas/eledhel/central-city/old-city-armorer/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/tailor.c",
        "west", "/areas/eledhel/central-city/old-city-tailor-two/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/central-city/17x2.c");
    addExit("south", "/areas/eledhel/central-city/17x0.c");
}
