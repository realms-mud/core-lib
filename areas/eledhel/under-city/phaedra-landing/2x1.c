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
    addItem("/lib/environment/items/furniture/bed.c", "west");
    addItem("/lib/environment/items/objects/field-surgery-kit.c", "east");
    addExit("north", "/areas/eledhel/under-city/phaedra-branch/2x3.c");
    addExit("south", "/areas/eledhel/under-city/phaedra-mechanism/2x2.c");
}
