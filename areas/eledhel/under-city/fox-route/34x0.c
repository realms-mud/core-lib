//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

public void Setup()
{
    underCityCaveRoom::Setup();
    setShortDescription("The cavern roof dips low over a shelf of "
        "broken limestone.");
    configureFoxRouteSegment(34);
}
