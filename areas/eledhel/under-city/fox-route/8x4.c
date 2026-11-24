//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/caves/timber-supports.c", "north");
    addExit("north", "/areas/eledhel/under-city/fox-route/8x3.c");
    addExit("south", "/areas/eledhel/under-city/fox-route/8x5.c");
}
