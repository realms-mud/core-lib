//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/water/stone-drainage-channel.c",
        "west");
    addItem("/lib/environment/items/objects/packing-crate.c", "north");
    addExit("north", "/areas/eledhel/under-city/fox-route/8x5.c");
    addExit("south", "/areas/eledhel/under-city/fox-route/8x7.c");
}
