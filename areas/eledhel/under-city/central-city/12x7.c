//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/water/stone-drainage-channel.c",
        "east");
    addItem("/lib/environment/items/objects/cistern-hand-pump.c", "north");
    addItem("/lib/environment/items/objects/torch-bin.c", "west");
    addItem("/lib/environment/items/furniture/bench.c", "south");
    addItem("/lib/environment/items/objects/packing-crate.c", "east");
    addExit("north", "/areas/eledhel/under-city/central-city/12x8.c");
    addExit("south", "/areas/eledhel/under-city/central-city/12x6.c");
}
