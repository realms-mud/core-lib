//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/caves/calcite-rib.c", "west");
    addItem("/lib/environment/items/objects/stone-pile.c", "east");
    addExit("south", "/areas/eledhel/under-city/natural-caverns/7x1.c");
    addExit("north", "/areas/eledhel/under-city/natural-caverns/7x3.c");
}
