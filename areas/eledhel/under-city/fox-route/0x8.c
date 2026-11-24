//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addItem("/lib/environment/items/objects/packing-crate.c", "west");
    addExit("south", "/areas/eledhel/under-city/fox-route/0x9.c");
    addExit("north", "/areas/eledhel/under-city/fox-route/0x7.c");
}
