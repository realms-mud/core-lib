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
    addItem("/lib/environment/items/objects/stone-pile.c", "north");
    addExit("west", "/areas/eledhel/under-city/central-city/16x6.c");
    addExit("south", "/areas/eledhel/under-city/central-city/17x5.c");
    addExit("east", "/areas/eledhel/under-city/central-city/18x6.c");
}
