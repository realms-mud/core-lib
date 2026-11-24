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
    addExit("west", "/areas/eledhel/under-city/southern-city/15x7.c");
    addExit("east", "/areas/eledhel/under-city/southern-city/17x7.c");
    addExit("south", "/areas/eledhel/under-city/southern-city/16x6.c");
}
