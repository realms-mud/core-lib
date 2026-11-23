//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("The finished tunnel drops beneath a low "
        "arch of fitted limestone blocks.");
    addItem("/lib/environment/items/objects/stone-pile.c", "north");
    configureFoxRouteSegment(4);
}
