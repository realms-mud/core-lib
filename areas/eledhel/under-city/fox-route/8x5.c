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
    addItem("/lib/environment/items/objects/bucket.c", "west");
    addExit("north", "/areas/eledhel/under-city/fox-route/8x4.c");
    addExit("south", "/areas/eledhel/under-city/fox-route/8x6.c");
}
