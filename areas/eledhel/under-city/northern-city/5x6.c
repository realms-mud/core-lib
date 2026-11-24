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
    addItem("/areas/eledhel/under-city/items/drainage-grate.c", "north");
    addItem("/lib/environment/items/lighting/sconce.c", "west");
    addExit("east", "/areas/eledhel/under-city/northern-city/6x6.c");
    addExit("west", "/areas/eledhel/under-city/phaedra-mechanism/2x2.c");
}
