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
    addExit("north", "/areas/eledhel/under-city/southern-city/12x8.c");
    addExit("south", "/areas/eledhel/under-city/southern-city/12x6.c");
    addExit("east", "/areas/eledhel/under-city/southern-city/13x7.c");
}
