//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A neighborhood inn and smithy face the street");
    addObject("/areas/eledhel/central-city/characters/inn-traveler.c");
    addBuildingWithDoor(
        "/lib/environment/buildings/shops/weaponsmith.c", "west",
        "/areas/eledhel/central-city/old-city-hammer-smith/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/inn.c",
        "east", "/areas/eledhel/central-city/wayfarer-inn/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/central-city/20x2.c");
    addExit("south", "/areas/eledhel/central-city/20x0.c");
}
