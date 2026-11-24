//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/caves/timber-supports.c", "east");
    addItem("/lib/environment/items/objects/stone-pile.c", "south");
    addExit("east", "/areas/eledhel/under-city/fox-route/1x9.c");
    addExit("north", "/areas/eledhel/under-city/fox-route/0x8.c");
}
