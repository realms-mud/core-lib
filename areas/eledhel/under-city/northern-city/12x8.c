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
    addItem("/areas/eledhel/under-city/items/drainage-grate.c", "north");
    addExit("south", "/areas/eledhel/under-city/northern-city/12x7.c");
    addExit("north", "/areas/eledhel/under-city/northern-city/12x9.c");
    addExit("east", "/areas/eledhel/under-city/northern-city/13x8.c");
}
