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
    addItem("/areas/eledhel/under-city/items/drainage-grate.c", "north");
    addExit("east", "/areas/eledhel/under-city/central-city/9x4.c");
    addExit("south", "/areas/eledhel/under-city/central-city/8x5.c");
}
