//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("A compact forge for balancing and sharpening "
        "small blades");
    addItem("/lib/environment/items/lighting/forge-fire.c", "east");
    addItem("/lib/environment/items/furniture/workbench.c", "north");
    addExit("west",
        "/areas/eledhel/central-city/old-city-dagger-smith/0x0.c");
}
