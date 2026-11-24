//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/water/mineral-pool.c", "north");
    addExit("west", "/areas/eledhel/under-city/natural-caverns/0x0.c");
    addExit("east", "/areas/eledhel/under-city/natural-caverns/2x0.c");
}
