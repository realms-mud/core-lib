//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/water/stone-drainage-channel.c",
        "east");
    addItem("/lib/environment/items/objects/bucket.c", "south");
    addExit("north", "/areas/eledhel/under-city/central-city/12x5.c");
    addExit("south", "/areas/eledhel/under-city/central-city/12x3.c");
    addExit("west", "/areas/eledhel/under-city/aegis-branch/11x4.c");
    addExit("east", "/areas/eledhel/under-city/central-city/13x4.c");
}
