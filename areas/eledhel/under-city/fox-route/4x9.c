//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/caves/timber-supports.c", "south");
    addItem("/lib/environment/items/objects/broom.c", "north");
    addExit("east", "/areas/eledhel/under-city/fox-route/5x9.c");
    addExit("west", "/areas/eledhel/under-city/fox-route/3x9.c");
}
