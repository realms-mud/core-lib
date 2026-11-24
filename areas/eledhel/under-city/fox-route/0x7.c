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
    addItem("/lib/environment/items/objects/bucket.c", "east");
    addExit("south", "/areas/eledhel/under-city/fox-route/0x8.c");
    addExit("north", "/areas/eledhel/under-city/fox-route/0x6.c");
}
