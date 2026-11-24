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
    addItem("/lib/environment/items/objects/stone-pile.c", "north");
    addExit("north", "/areas/eledhel/under-city/fox-route/8x8.c");
    addExit("west", "/areas/eledhel/under-city/fox-route/7x9.c");
}
