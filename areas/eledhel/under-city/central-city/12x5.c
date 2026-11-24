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
    addItem("/lib/environment/items/lighting/sconce.c", "west");
    addExit("north", "/areas/eledhel/under-city/central-city/12x6.c");
    addExit("south", "/areas/eledhel/under-city/central-city/12x4.c");
    addExit("west", "/areas/eledhel/under-city/central-city/11x5.c");
    addExit("east", "/areas/eledhel/under-city/central-city/13x5.c");
}
