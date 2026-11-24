//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/caves/timber-supports.c", "west");
    addItem("/lib/environment/items/objects/paired-climbing-ropes.c",
        "north");
    addExit("south", "/areas/eledhel/under-city/natural-caverns/7x3.c");
    addExit("north", "/areas/eledhel/under-city/natural-caverns/7x5.c");
}
