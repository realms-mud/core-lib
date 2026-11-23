//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("The swordsmith's forge and grinding benches");
    addItem("/lib/environment/items/lighting/forge-fire.c", "east");
    addItem("/lib/environment/items/furniture/workbench.c", "north");
    addExit("west", "/areas/eledhel/central-city/old-city-swordsmith/0x0.c");
}
