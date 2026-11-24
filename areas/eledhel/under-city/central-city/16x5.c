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
    addItem("/lib/environment/items/objects/bucket.c", "east");
    addItem("/areas/eledhel/under-city/items/drainage-grate.c", "south");
    addExit("east", "/areas/eledhel/under-city/central-city/17x5.c");
    addExit("west", "/areas/eledhel/under-city/central-city/15x5.c");
    addExit("north", "/areas/eledhel/under-city/central-city/16x6.c");
}
