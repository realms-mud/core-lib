//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

public void Setup()
{
    underCityCaveRoom::Setup();
    setShortDescription("A steep, near-vertical climb rises toward "
        "a narrow crack in the hillside.");
    configureFoxRouteSegment(40);
}
