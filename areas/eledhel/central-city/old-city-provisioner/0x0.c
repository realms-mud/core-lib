//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("A provisioner's shop with bread, travel stores, "
        "and household staples.");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/marine/barrel.c", "east");
    addShop("/lib/environment/shopInventories/provisions.c");
    addObject(
        "/areas/eledhel/central-city/characters/old-city-provisioner.c");
    addObject(
        "/areas/eledhel/central-city/characters/provisioner-customer.c");
    addExit("east",
        "/areas/eledhel/central-city/old-city-provisioner/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/20x0.c",
        "/lib/environment/doors/plank-door.c");
}
