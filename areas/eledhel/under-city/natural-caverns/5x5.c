//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/lib/environment/features/caves/timber-supports.c", "north");
    addItem("/lib/environment/items/objects/paired-climbing-ropes.c",
        "east");
    addExit("east", "/areas/eledhel/under-city/natural-caverns/6x5.c");
    addExit("west", "/areas/eledhel/under-city/natural-caverns/4x5.c");
}
