//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    underCityRoom::Setup();
    addFeature("/lib/environment/features/caves/timber-supports.c", "north");
    addItem("/lib/environment/items/objects/stone-pile.c", "east");
    addExit("up", "/areas/eledhel/central-city/palace/2x3.c");
    addExit("down", "/areas/eledhel/under-city/trunk/0x0.c");
}
