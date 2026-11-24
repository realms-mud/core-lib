//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addItem("/areas/eledhel/under-city/items/silted-sluice.c", "south");
    addExit("east", "/areas/eledhel/under-city/fox-route/6x9.c");
    addExit("west", "/areas/eledhel/under-city/fox-route/4x9.c");
}
