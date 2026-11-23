//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("A crowded smithing and leatherworking block");
    addObject("/areas/eledhel/central-city/characters/sword-shopper.c");
    addBuildingWithDoor(
        "/lib/environment/buildings/shops/weaponsmith.c", "east",
        "/areas/eledhel/central-city/old-city-swordsmith/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor(
        "/lib/environment/buildings/shops/leatherworking-shop.c", "west",
        "/areas/eledhel/central-city/old-city-saddlery/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/central-city/17x1.c");
    addExit("south", "/areas/eledhel/southern-city/17x9.c");
}
