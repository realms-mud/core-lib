//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/water/stone-drainage-channel.c",
        "south");
    addItem("/lib/environment/items/objects/cistern-hand-pump.c", "north");
    addItem("/lib/environment/items/objects/torch-bin.c", "west");
    addItem("/lib/environment/items/objects/packing-crate.c", "east");
    addExit("west", "/areas/eledhel/under-city/northern-city/22x7.c");
    addExit("north", "/areas/eledhel/under-city/naval-branch/23x8.c");
}
