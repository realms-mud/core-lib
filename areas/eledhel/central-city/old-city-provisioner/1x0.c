//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    setShortDescription("A cool stockroom for sacks, casks, and shop "
        "deliveries");
    addItem("/lib/environment/items/furniture/small-shelf.c", "north");
    addItem("/lib/environment/items/marine/barrel.c", "east");
    addExit("west",
        "/areas/eledhel/central-city/old-city-provisioner/0x0.c");
}
