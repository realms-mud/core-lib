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
    addItem("/lib/environment/items/furniture/book-shelf.c", "north");
    addItem("/areas/eledhel/under-city/items/drainage-grate.c", "west");
    addExit("east", "/areas/eledhel/under-city/northern-city/19x8.c");
    addExit("west", "/areas/eledhel/under-city/museum-branch/17x8.c");
    addExit("up", "/areas/eledhel/northern-city/library/0x0.c");
    addExit("down", "/areas/eledhel/under-city/fox-route/8x0.c");
}
