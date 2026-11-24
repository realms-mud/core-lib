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
    addItem("/lib/environment/items/lighting/sconce.c", "east");
    addExit("west", "/areas/eledhel/under-city/northern-city/22x8.c");
    addExit("south", "/areas/eledhel/under-city/northern-city/23x7.c");
    addExit("up", "/areas/eledhel/northern-city/naval-headquarters/0x1.c");
}
