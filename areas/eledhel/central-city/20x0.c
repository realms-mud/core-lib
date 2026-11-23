//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Smith and provisioner fronts share this block");
    addObject("/areas/eledhel/central-city/characters/provision-shopper.c");
    addBuildingWithDoor(
        "/lib/environment/buildings/shops/weaponsmith.c", "west",
        "/areas/eledhel/central-city/old-city-dagger-smith/0x0.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor(
        "/lib/environment/buildings/shops/general-shop.c", "east",
        "/areas/eledhel/central-city/old-city-provisioner/0x0.c",
        "/lib/environment/doors/plank-door.c");

    addExit("north", "/areas/eledhel/central-city/20x1.c");
    addExit("south", "/areas/eledhel/southern-city/20x9.c");
}
