//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-fortress-hall.c");
    setShortDescription("The Aegis Guard's equipment room");
    addItem("/lib/environment/items/military/weapon-rack.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "east");
    addExit("north", "/areas/eledhel/central-city/aegis-hall/1x0.c");
    addExit("west", "/areas/eledhel/central-city/aegis-hall/0x1.c");
}
