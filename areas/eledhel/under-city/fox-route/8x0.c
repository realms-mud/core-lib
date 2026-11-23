//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/under-city/underCityRoom.c";

public void Setup()
{
    underCityRoom::Setup();
    setShortDescription("A shelter chamber widens beside a shallow "
        "cistern cut into the tunnel floor.");
    addItem("/lib/environment/items/objects/stone-pile.c", "east");
    configureFoxRouteSegment(8);
}
