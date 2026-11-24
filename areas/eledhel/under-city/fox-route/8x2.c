//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addItem("/lib/environment/items/objects/cistern-hand-pump.c", "east");
    addItem("/lib/environment/items/objects/torch-bin.c", "west");
    addItem("/lib/environment/items/furniture/chest.c", "north");
    addExit("north", "/areas/eledhel/under-city/fox-route/8x1.c");
    addExit("south", "/areas/eledhel/under-city/fox-route/8x3.c");
}
