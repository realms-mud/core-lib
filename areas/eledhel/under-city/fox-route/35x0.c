//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityCaveRoom.c";

public void Setup()
{
    underCityCaveRoom::Setup();
    setShortDescription("A broader chamber holds a jumble of pale "
        "stones and a trickle of clear water.");
    addItem("/lib/environment/items/objects/stone-pile.c", "east");
    configureFoxRouteSegment(35);
}
