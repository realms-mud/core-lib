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
    addExit("north", "/areas/eledhel/under-city/central-city/12x7.c");
    addExit("south", "/areas/eledhel/under-city/central-city/12x5.c");
    addExit("west", "/areas/eledhel/under-city/central-city/11x6.c");
    addExit("east", "/areas/eledhel/under-city/werric-branch/13x6.c");
}
