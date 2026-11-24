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
    addItem("/lib/environment/items/objects/bucket.c", "west");
    addExit("east", "/areas/eledhel/under-city/central-city/10x4.c");
    addExit("west", "/areas/eledhel/under-city/central-city/8x4.c");
    addExit("north", "/areas/eledhel/under-city/central-city/9x5.c");
}
