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
    addExit("north", "/areas/eledhel/under-city/southern-city/12x4.c");
    addExit("south", "/areas/eledhel/under-city/southern-city/12x2.c");
    addExit("west", "/areas/eledhel/under-city/southern-city/11x3.c");
}
