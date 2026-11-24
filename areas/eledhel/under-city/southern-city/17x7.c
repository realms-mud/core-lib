//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/water/stone-drainage-channel.c",
        "south");
    addItem("/lib/environment/items/objects/packing-crate.c", "north");
    addExit("west", "/areas/eledhel/under-city/southern-city/16x7.c");
    addExit("east", "/areas/eledhel/under-city/southern-city/18x7.c");
    addExit("south", "/areas/eledhel/under-city/southern-city/17x6.c");
}
