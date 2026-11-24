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
    addExit("west", "/areas/eledhel/under-city/southern-city/18x6.c");
    addExit("north", "/areas/eledhel/under-city/southern-city/19x7.c");
    addExit("east", "/areas/eledhel/under-city/southern-city/20x6.c");
}
