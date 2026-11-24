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
    addItem("/lib/environment/items/objects/stone-pile.c", "east");
    addExit("west", "/areas/eledhel/under-city/central-city/12x6.c");
    addExit("east", "/areas/eledhel/under-city/central-city/14x6.c");
    addExit("north", "/areas/eledhel/under-city/central-city/13x5.c");
    addExit("up", "/areas/eledhel/central-city/triumvirate-temple/0x1.c");
}
