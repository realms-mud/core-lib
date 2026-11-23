//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("The finished tunnel runs straight and level "
        "through old, carefully laid stone.");
    configureFoxRouteSegment(14);
}
