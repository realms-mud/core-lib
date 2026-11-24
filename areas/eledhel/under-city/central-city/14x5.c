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
    addItem("/lib/environment/items/objects/stone-pile.c", "north");
    addExit("east", "/areas/eledhel/under-city/central-city/15x5.c");
    addExit("west", "/areas/eledhel/under-city/central-city/13x5.c");
    addExit("north", "/areas/eledhel/under-city/central-city/14x6.c");
    addExit("south", "/areas/eledhel/under-city/central-city/14x4.c");
    addExit("up", "/areas/eledhel/central-city/palace/hidden-passage.c");
}
