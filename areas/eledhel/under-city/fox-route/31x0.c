//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

public void Setup()
{
    underCityCaveRoom::Setup();
    configureFoxRouteSegment(31);
}
