//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addItem("/lib/environment/items/objects/packing-crate.c", "south");
    addExit("east", "/areas/eledhel/under-city/fox-route/4x9.c");
    addExit("west", "/areas/eledhel/under-city/fox-route/2x9.c");
}
