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
    addItem("/areas/eledhel/under-city/items/drainage-grate.c", "east");
    addExit("north", "/areas/eledhel/under-city/library-branch/18x8.c");
    addExit("east", "/areas/eledhel/under-city/northern-city/19x7.c");
}
