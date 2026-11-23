//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/limestone-interior-shop.c");
    setShortDescription("A narrow forge shop specializing in daggers and "
        "small blades.");
    addItem("/lib/environment/items/furniture/counter.c", "north");
    addItem("/lib/environment/items/military/weapon-rack.c", "east");
    addShop("/lib/environment/shopInventories/dagger-smith.c");
    addObject("/areas/eledhel/central-city/characters/old-city-dagger-smith.c");
    addObject("/areas/eledhel/central-city/characters/dagger-customer.c");
    addExit("east",
        "/areas/eledhel/central-city/old-city-dagger-smith/1x0.c");
    addExitWithDoor("west", "/areas/eledhel/central-city/20x0.c",
        "/lib/environment/doors/plank-door.c");
}
