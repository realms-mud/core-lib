//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/water/mineral-pool.c", "south");
    addItem("/lib/environment/items/objects/stone-pile.c", "east");
    addExit("west", "/areas/eledhel/under-city/natural-caverns/5x0.c");
    addExit("east", "/areas/eledhel/under-city/natural-caverns/7x0.c");
}
