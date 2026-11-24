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
    addItem("/lib/environment/items/objects/broom.c", "north");
    addExit("west", "/areas/eledhel/under-city/central-city/14x6.c");
    addExit("south", "/areas/eledhel/under-city/central-city/15x5.c");
    addExit("east", "/areas/eledhel/under-city/central-city/16x6.c");
}
