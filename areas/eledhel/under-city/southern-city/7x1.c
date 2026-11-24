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
    addItem("/lib/environment/items/objects/broom.c", "east");
    addExit("west", "/areas/eledhel/under-city/southern-city/6x1.c");
    addExit("east", "/areas/eledhel/under-city/southern-city/8x1.c");
}
