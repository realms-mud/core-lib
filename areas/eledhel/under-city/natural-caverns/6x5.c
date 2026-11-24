//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/caves/calcite-rib.c", "south");
    addItem("/lib/environment/items/objects/stone-pile.c", "north");
    addExit("east", "/areas/eledhel/under-city/natural-caverns/7x5.c");
    addExit("west", "/areas/eledhel/under-city/natural-caverns/5x5.c");
}
