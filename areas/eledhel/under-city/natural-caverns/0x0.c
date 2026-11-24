//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/caves/calcite-rib.c", "north");
    addFeature("/lib/environment/features/water/mineral-pool.c", "east");
    addExit("up", "/areas/eledhel/under-city/fox-route/0x1.c");
    addExit("east", "/areas/eledhel/under-city/natural-caverns/1x0.c");
}
