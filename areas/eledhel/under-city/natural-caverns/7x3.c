//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/caves/calcite-rib.c", "south");
    addExit("south", "/areas/eledhel/under-city/natural-caverns/7x2.c");
    addExit("north", "/areas/eledhel/under-city/natural-caverns/7x4.c");
}
